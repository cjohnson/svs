// I'm at the start of the world

module top_module (
    input logic clock,
    input logic reset
);
    logic [3:0] counter, next_counter;
    always_comb begin
        next_counter = counter + 1;
    end

    // My D Flip-Flop register!
    always_ff @(posedge clock) begin
        if (reset) begin
            counter <= 0;
        end else begin
            counter <= next_counter;
        end
    end
endmodule

/* I span
muliple lines */

// I'm at the end of the road
