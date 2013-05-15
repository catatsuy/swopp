module TestTop();
    reg CLK;
    reg  [31:0] cycle;

    wire [7:0] ot_cnt;
    Counter cnt(CLK, ot_cnt);

    initial begin
        CLK = 0;
        cycle = 0;
        cnt.cnt = 0;
    end

    always #50 CLK = ~CLK;

    always @(posedge CLK) begin
        cycle <= cycle + 1;
        if (cycle > (`HALT_CYCLE - 10))
            $write("%d %d\n", cycle, ot_cnt);
        if (cycle >= `HALT_CYCLE) $finish;
    end
endmodule

