class SmallestInfiniteSet {
public:
	vector<int> res;
	set<int> s;
	bool flag = false;

	SmallestInfiniteSet() {

	}

	int popSmallest() {
		if (flag == false) {
			for (int i = 1; i <= 1000; ++i)
			{
				/* code */
				s.insert(i);
				flag = true;
			}

		}
		auto it = s.begin();
		int x = *it;
		s.erase(*it);
		return x;
	}

	void addBack(int num) {
		s.insert(num);
	}
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */