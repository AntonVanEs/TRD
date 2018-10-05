tests:
	cd test && ${MAKE} all

clean:
	rm -f trd.log trd.pdf trd.toc trd.aux texput.log trd.out
	cd test && ${MAKE} clean
	cd aux && ${MAKE} clean

update:
	git reset --hard HEAD
	chmod -R a+r .
	find -type d -exec chmod a+x {} \;

archive:
	git archive --prefix=trd/ --format=tar HEAD | gzip > trd-`date +%Y%m%d`.tar.gz
	chmod a+r trd-`date +%Y%m%d`.tar.gz
