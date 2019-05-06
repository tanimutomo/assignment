// 全体のプロセスの個数は10個

int succ(i) {
    // 右側のプロセスidを取得する
}

int pred(i) {
    // 左側のプロセス
}

int min(int card[10]) {
    // cardのなかで最小値とそのindexを検索する関数
    return mininum_value, mininum_value_index;
}

int max(int card[10]) {
    // cardのなかで最小値とそのindexを検索する関数
    return maxinum_value, maxinum_value_index
}

Process Pi(pid i, int m, int card[10]) {
    init();
    // sortされたかどうかを判断するためのフラグを用意
    int succ_sorted = 0; pred_sorted = 0;
    
    // 各変数の定義
    int mx, mxi, mn, mni;
    int pre_send_succ, pre_send_pred;

    while(1) {
        // 右側と入れ替える
        if (pid != 10) {
            mx, mxi = max(card);
            NBsend(succ(i), mx);
            NBrec(succ(i), card[mxi]);
            // 前回送ったcardが返ってきたら，ソートが終了していると判断する
            if (pre_send_succ == card[mxi]) {
                succ_sorted = 1;
            }
            pre_send_succ = mx;
        }

        // 左側と入れ替える
        if (pid != 0) {
            mn, mni = min(card);
            NBsend(pred(i), mn);
            NBrec(pred(i), card[mni]);
            // 前回送ったcardが返ってきたら，ソートが終了していると判断する
            if (pre_send_pred == card[mni]) {
                pred_sorted = 1;
            }
            pre_send_pred = mn;
        }

        // 両側のprocessがソートされていれば，loopを終了する
        if (pre_sorted == 1 && succ_sorted == 1) {
            exit;
        }
    }
}
