TESTS=suffix_array linsolve scc name fordfulkerson ff_dijkstra dijkstra bellmanford isprime uggd kruskal fenwick lis graham 2sat graham2 partition kmp ahocorasick bignum
CLEAN=$(addsuffix /clean,$(TESTS))
TARGETS=$(addsuffix /target,$(TESTS))

all: $(TARGETS)

$(TARGETS):
	cd $(dir $@) && $(MAKE) test

clean: $(CLEAN)

$(CLEAN):
	cd $(dir $@) && $(MAKE) clean
