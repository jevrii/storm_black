#include <cstdint>
#include <functional>
#include <vector>
#include <optional>

using namespace std;

template<typename T>
class segment_tree {
public:
    using id_t = size_t;
    using pos_t = size_t;
    using combine_func_t = std::function<T(T, T)>;

    struct range_t {
        pos_t l = 0;
        pos_t r = 0;

        size_t len() const {
            return r - l;
        }

        pos_t mid() const {
            return (r + l) / 2;
        }
    };

private:
    struct node_t {
        const id_t id = 0;
        const range_t range;

        node_t left_child() const {
            return {id << 1, {range.l, range.mid()}};
        }

        node_t right_child() const {
            return {id << 1 | 1, {range.mid(), range.r}};
        }
    };

public:
    segment_tree(const vector<T>& a, combine_func_t func) {
        combine_func_ = func;
        n_ = a.size();
        a_ = a;
        t_.resize(n_ * 4);
        fill(t_.begin(), t_.end(), 0);
        build(a, root());
    }

    T ask(const range_t& query) {
        return ask(query, root()).value();
    }

    // set a[pos] = val
    void update(pos_t pos, T val) {
        update(pos, val, root());
        a_[pos] = val;
    }

    std::optional<pos_t> ask_lower(std::function<bool(T)> pred) {
        return ask_lower(pred, root());
    }

    T value(pos_t pos) {
        return a_[pos];
    }


private:
    void build(const vector<T>& a, const node_t& node) {
        if (node.range.len() == 1) {
            t_[node.id] = a[node.range.l];
            return;
        }
        build(a, node.left_child());
        build(a, node.right_child());
        t_[node.id] = combine_func_(t_[node.left_child().id], t_[node.right_child().id]);
    }

    node_t root() const {
        return {1, {0, n_}};
    }

private:
    std::optional<T> ask(const range_t& query, const node_t& node) {
        if (query.r <= node.range.l || node.range.r <= query.l) {
            return std::nullopt;
        }

        if (query.l <= node.range.l && node.range.r <= query.r) {
            return t_[node.id];
        }

        auto lhs = ask(query, node.left_child());
        auto rhs = ask(query, node.right_child());
        if (!lhs) {
            return rhs;
        }
        if (!rhs) {
            return lhs;
        }
        return combine_func_(lhs.value(), rhs.value());
    }

    std::optional<pos_t> ask_lower(std::function<bool(T)> pred, node_t node) {
        if (!pred(t_[node.id])) {
            return std::nullopt;
        }

        if (node.range.len() == 1) {
            if (pred(t_[node.id])) {
                return node.range.l;
            }
            return std::nullopt;
        }

        if (pred(t_[node.left_child().id])) {
            return ask_lower(pred, node.left_child());
        }
        return ask_lower(pred, node.right_child());
    }

    void update(pos_t pos, T val, node_t node) {
        if (pos < node.range.l || pos >= node.range.r) {
            return;
        }

        if (node.range.len() == 1) {
            t_[node.id] = val;
            return;
        }

        update(pos, val, node.left_child());
        update(pos, val, node.right_child());

        t_[node.id] = combine_func_(t_[node.left_child().id], t_[node.right_child().id]);
    }

private:
    size_t n_;
    vector<T> t_;
    vector<T> a_;
    combine_func_t combine_func_ = nullptr;
};