bool lexi_cmp (punt p, punt q) { return (p.y != q.y) ? (p.y < q.y) : (p.x < q.x); }

struct graham_cmp {
	punt o; graham_cmp (punt _o) : o(_o) { }
	bool operator() (punt p, punt q) const {
		int d = direction (o, p, q);
		return (d != 0) ? (d > 0) : (dot(p-o, p-o) < dot(q-o, q-o));
	}
};

void graham_scan (vector<punt> &punten, list< list<punt> > &hull) {
	// neem extreem punt
	punt o = *min_element (punten.begin(), punten.end(), lexi_cmp);
	// sorteren op hoek, dan afstand tot "o"
	sort (punten.begin(), punten.end(), graham_cmp (o));
	// "o" komt op eerste positie
	assert (punten.front().x == o.x && punten.front().y == o.y);

	// richting van bochten in de convex hull die we gaan bouwen.
	// (Is altijd hetzelfde (behalve als alle punten op een lijn).)
	// Hangt af van volgorde in "cross" en basispunt in "direction".
	int d = direction (o, *(punten.begin()+1), punten.back());

	hull.clear();

	// laatste halfopen zijde van convex hull (NB: loop doet back en front niet)
	hull.push_back(list<punt>());
	for (vector<punt>::reverse_iterator it = punten.rbegin()+1;
	     it != punten.rend()-1 && 0 == direction (punten.back(), *it, o); ++it) {
		hull.back().push_back(*it);
	}
	hull.back().push_back (o);

	// eerste punt van eerste halfopen zijde van convex hull
	hull.push_back (list<punt>());
	hull.back().push_back (*(punten.begin()+1));

	for (vector<punt>::iterator it = punten.begin()+2; it != punten.end(); ++it) {
		// Zolang richting echt fout, gooi vorig weg.
		while (-1 == d * direction ((++hull.rbegin())->back(),
		                            hull.back().back(), *it)) {
			hull.pop_back();
		}
		// echt bocht om? Begin dan een nieuwe zijde.
		if (0 != direction ((++hull.rbegin())->back(), hull.back().back(), *it)) {
			hull.push_back (list<punt>());
		}
		hull.back().push_back(*it);
	}
}
