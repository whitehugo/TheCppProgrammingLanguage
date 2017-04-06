TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

HEADERS += \
    myvector.h \
    test.h \
    ../stl/algo.h \
    ../stl/algobase.h \
    ../stl/algorithm \
    ../stl/alloc.h \
    ../stl/bitset \
    ../stl/bvector.h \
    ../stl/char_traits.h \
    ../stl/concept_checks.h \
    ../stl/container_concepts.h \
    ../stl/defalloc.h \
    ../stl/deque \
    ../stl/deque.h \
    ../stl/function.h \
    ../stl/functional \
    ../stl/hash_map \
    ../stl/hash_map.h \
    ../stl/hash_set \
    ../stl/hash_set.h \
    ../stl/hashtable.h \
    ../stl/heap.h \
    ../stl/iterator \
    ../stl/iterator.h \
    ../stl/limits \
    ../stl/list \
    ../stl/list.h \
    ../stl/map \
    ../stl/map.h \
    ../stl/memory \
    ../stl/multimap.h \
    ../stl/multiset.h \
    ../stl/numeric \
    ../stl/pair.h \
    ../stl/pthread_alloc \
    ../stl/pthread_alloc.h \
    ../stl/queue \
    ../stl/rope \
    ../stl/rope.h \
    ../stl/ropeimpl.h \
    ../stl/sequence_concepts.h \
    ../stl/set \
    ../stl/set.h \
    ../stl/slist \
    ../stl/slist.h \
    ../stl/stack \
    ../stl/stack.h \
    ../stl/stdexcept \
    ../stl/stl_algo.h \
    ../stl/stl_algobase.h \
    ../stl/stl_alloc.h \
    ../stl/stl_bvector.h \
    ../stl/stl_config.h \
    ../stl/stl_construct.h \
    ../stl/stl_ctraits_fns.h \
    ../stl/stl_deque.h \
    ../stl/stl_exception.h \
    ../stl/stl_function.h \
    ../stl/stl_hash_fun.h \
    ../stl/stl_hash_map.h \
    ../stl/stl_hash_set.h \
    ../stl/stl_hashtable.h \
    ../stl/stl_heap.h \
    ../stl/stl_iterator.h \
    ../stl/stl_iterator_base.h \
    ../stl/stl_list.h \
    ../stl/stl_map.h \
    ../stl/stl_multimap.h \
    ../stl/stl_multiset.h \
    ../stl/stl_numeric.h \
    ../stl/stl_pair.h \
    ../stl/stl_queue.h \
    ../stl/stl_range_errors.h \
    ../stl/stl_raw_storage_iter.h \
    ../stl/stl_relops.h \
    ../stl/stl_rope.h \
    ../stl/stl_set.h \
    ../stl/stl_slist.h \
    ../stl/stl_stack.h \
    ../stl/stl_string_fwd.h \
    ../stl/stl_tempbuf.h \
    ../stl/stl_threads.h \
    ../stl/stl_tree.h \
    ../stl/stl_uninitialized.h \
    ../stl/stl_vector.h \
    ../stl/string \
    ../stl/tempbuf.h \
    ../stl/tree.h \
    ../stl/type_traits.h \
    ../stl/utility \
    ../stl/valarray \
    ../stl/vector \
    ../stl/vector.h \
    complex.h

SOURCES += main.cpp \
    myvector.cpp \
    test.cpp \
    complex.cpp

DISTFILES += \
    .gitignore
