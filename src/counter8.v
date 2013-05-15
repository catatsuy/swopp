module Counter(CLK, out);
    input CLK;
    output [7:0] out;

    reg [7:0] counter;
    assign out = counter;
    always @(posedge CLK) begin
        counter <= counter + 1;
    end
endmodule

