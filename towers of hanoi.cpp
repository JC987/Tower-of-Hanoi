#include <iostream>

#include <vector>

using namespace std;
int main() {

	vector<int> tower[3];
	int n, ring_candidate=1, to, from=0, steps = 0; 
	cout << "Please enter a number(greater than 0) of rings to move: "<<endl;
	cin >> n;
	
  	bool isOdd = (n%2 == 1);

	for (int i = n + 1; i >= 1; i--)
		tower[0].push_back(i);

	tower[1].push_back(n + 1);
	tower[2].push_back(n + 1);

	if (isOdd) 
		to = 1;
	else 
		to = 2;

	while (tower[1].size()<n + 1) { 
    	//move ring
		tower[to].push_back(tower[from].back());
		tower[from].pop_back();
		steps++;

	 	// print step
		cout << "Step " << steps <<": Move ring "<< ring_candidate << " from tower " << char(from + 65) << " to tower " << char(to + 65) << endl;
	

		//prepair next move
  		if (tower[(to + 1) % 3].back() < tower[(to + 2) % 3].back())
				from = (to + 1) % 3;
		else
				from = (to + 2) % 3;
			

    	if(isOdd){
    		if (tower[(from)].back() < tower[(from + 1) % 3].back())
				to = (from + 1) % 3;
			else
				to = (from + 2) % 3;
    	}
    	else{
    		if (tower[(from)].back() < tower[(from + 2) % 3].back())
				to = (from + 2) % 3;
			else
				to = (from + 1) % 3;
		}

		ring_candidate = (tower[from].back()); 
  
		
	}
	return 0;
}