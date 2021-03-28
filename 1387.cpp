class Solution {
public:
    int getKth(int lo, int hi, int k) {

        vector<Node> nodes(1001);
        for(int i = lo; i <= hi; i++){
            nodes[i].num = i;
            nodes[i].keyval = getkeyval(i);
        }

        for(int i = lo; i < lo + k; i++){
            int mincnt = nodes[i].keyval;
            int minlocal = i;
            for(int j = i + 1; j <= hi; j++){
                if(nodes[j].keyval < mincnt){
                    mincnt = nodes[j].keyval;
                    minlocal = j;
                }

                if(nodes[j].keyval == mincnt){
                    if(nodes[j].num < nodes[minlocal].num) minlocal = j;
                }
            }
        
            Node temp = nodes[i];
            nodes[i] = nodes[minlocal];
            nodes[minlocal] = temp;
        }

        return nodes[lo+k-1].num;


    }

    class Node{
    public:
        int num=0;
        int keyval=0;

    };

    int getkeyval(int i){
        int cnt = 0;
        while(i != 1){
            if(i%2 ==0){
                i=i/2;
            }else{
                i= 3*i+1;
            }
            cnt++;
        }

        return cnt;
    }

};
