#include <iostream>
#include <vector>
using namespace std;

struct Edge {
    int to;     // 辺の行き先
    float weight; // 辺の重み
    Edge(int t, float w) : to(t), weight(w) { }
};
using Graph = vector<vector<Edge>>;

int main() {
    // 頂点数と辺数
    int N, M; cin >> N >> M;

    // グラフ
    Graph G(N);
    for (int i = 0; i < M; ++i) {
        int from, to;
        float weight;
        cin >> from >> to >> weight;
        G[from].push_back(Edge(to, weight));
    }

    //終点の数
    int K; cin >> K;

    //各頂点の値を管理する配列
    vector<float> value(N,0);

    //終点の値を入力
    for(int i= N-K; i < N; ++i){
        cin >> value[i];
    }

    //debug
    // for(int i = 0; i < N; ++i){
    //     cout << i <<" "<< value[i] << endl;
    // }

    //backwardで値を更新
    for(int i = N-K-1; i >= 0; --i){
        //重みが1かどうか
        bool flag = false;
        for(auto e: G[i]){
            if(e.weight == 1){
                flag = true;
                break;
            }
        }
        //flagがtrueなら最大値を取る
        if(flag){
            value[i] = -1e9;
            for(auto e: G[i]){
                value[i] = max(value[i], value[e.to] );
            }
        }
        //flagがfalseなら重みをかける
        else{
            for(auto e: G[i]){
                value[i] += value[e.to] * e.weight;
            }
        }

        
        
        cout << i <<" 番目の値は "<< value[i] << endl;
    } 
}
