class MedianFinder {
public:
    double median;
    
    priority_queue<int,vector<int>, greater<int> > right; 
	priority_queue<int> left;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
         if(left.empty() and right.empty()){
			median = num;
			left.push(num);
		}
		
		else if(left.size()==right.size()){
			if(num <= median){
				left.push(num);
				median = left.top();
			}
			else{
				right.push(num);
				median = right.top();
			}
		}
		else if(left.size()>right.size()){
			
			if(num <= median){
				right.push(left.top());
				left.pop();
				left.push(num);
			}
			else{
				right.push(num);
			}
			median = (left.top() + right.top())/2.0;
		}
		else{
			if(num > median){
				left.push(right.top());
				right.pop();
				right.push(num);
			}
			else{
				left.push(num);
			}
			median = (left.top() + right.top())/2.0;
		}
    }
    
    double findMedian() {
        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */