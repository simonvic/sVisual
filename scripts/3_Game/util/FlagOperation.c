class FlagOperation : Managed{
	int flag;
	
	void FlagOperation(int x = 0){
		flag = x;
	}
	
	void ~FlagOperation(){
	}
	
	FlagOperation not(){
		flag = ~flag;
		return this;
	}
	
	FlagOperation and(int x){
		flag &= x;
		return this;
	}
	
	FlagOperation set(int x){
		flag |= x;
		return this;
	}
	
	FlagOperation reset(int x){
		flag &= ~x;
		return this;
	}
	
	FlagOperation flip(int x){
		flag = (~flag & x) | (flag & ~x);
		return this;
	}
	
	bool check(int x){
		return flag & x;
	}
	
	int collect(){
		return flag;
	}
	
	string collectBinaryString(int digits = 32, int spacingEvery = 8){
		return toBinaryString(flag, digits, spacingEvery);
	}
	
	static string toBinaryString(int x, int digits = 32, int spacingEvery = 8){
		string result;
		int pos = 0;
		while (x > 0 || pos < digits){
			result = "" + (x & 1) + result;
			if((pos + 1) % spacingEvery == 0) result = " " + result;
			x >>= 1;
			pos++;
		}
		return result;
	}
		
}