# Test case for local memory load and store
	nop 	0;
	addi 	r1 = r0, 4095;
	addi	r2 = r0, 5;
	swl		[r2 + 0] = r1;
	shl		[r2 + 4] = r1;
	sbl 	[r2 + 8] = r1;
	lbl		r3 = [r2 + 0];
	lwl		r4 = [r2 + 4];
	lhl		r5 = [r2 + 8];
	lhl		r3 = [r2 + 0];
	lbl		r4 = [r2 + 4];
	lwl		r5 = [r2 + 8];
	nop		0;
	swl		[r2 + 0] = r1;
	shl		[r2 + 1] = r1;
	sbl 	[r2 + 2] = r1;
	lbl		r3 = [r2 + 0];
	lwl		r4 = [r2 + 1];
	lhl		r5 = [r2 + 2];
	lhl		r3 = [r2 + 0];
	lbl		r4 = [r2 + 1];
	lwl		r5 = [r2 + 2];
	nop		0;
	swl		[r0 + 1] = r1;
	shl		[r0 + 2] = r1;
	sbl 	[r0 + 4] = r1;
	lbl		r3 = [r0 + 1];
	lwl		r4 = [r0 + 2];
	lhl		r5 = [r0 + 4];
	lhl		r3 = [r0 + 1];
	lbl		r4 = [r0 + 2];
	lwl		r5 = [r0 + 4];
	nop		0;
	addi	r1 = r0, 111;
	sli		r2 = r1, 8;
	addi	r2 = r2, 222;
	sli 	r3 = r2, 16;
	addi 	r3 = r3, 84;
	swl		[r0 + 1] = r3;
	shl		[r0 + 1] = r2;
	sbl		[r0 + 1] = r1;
	lwl		r4 = [r0 + 1];
	lhl		r5 = [r0 + 1];
	lbl		r6 = [r0 + 1];
	nop 	0;
	swl		[r0 + 2] = r3;
	shl		[r0 + 2] = r2;
	sbl		[r0 + 2] = r1;
	lhul	r5 = [r0 + 2];
	lbul	r6 = [r0 + 2];
	halt;