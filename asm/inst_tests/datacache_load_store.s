# Test case for data cache load and store
	nop 	0;
	addi 	r1 = r0, 4095;
	addi	r2 = r0, 5;
	swc		[r2 + 0] = r1;
	shc		[r2 + 4] = r1;
	sbc 	[r2 + 8] = r1;
	lbc		r3 = [r2 + 0];
	lwc		r4 = [r2 + 4];
	lhc		r5 = [r2 + 8];
	lhc		r3 = [r2 + 0];
	lbc		r4 = [r2 + 4];
	lwc		r5 = [r2 + 8];
	nop		0;
	swc		[r2 + 0] = r1;
	shc		[r2 + 1] = r1;
	sbc 	[r2 + 2] = r1;
	lbc		r3 = [r2 + 0];
	lwc		r4 = [r2 + 1];
	lhc		r5 = [r2 + 2];
	lhc		r3 = [r2 + 0];
	lbc		r4 = [r2 + 1];
	lwc		r5 = [r2 + 2];
	nop		0;
	swc		[r0 + 1] = r1;
	shc		[r0 + 2] = r1;
	sbc 	[r0 + 4] = r1;
	lbc		r3 = [r0 + 1];
	lwc		r4 = [r0 + 2];
	lhc		r5 = [r0 + 4];
	lhc		r3 = [r0 + 1];
	lbc		r4 = [r0 + 2];
	lwc		r5 = [r0 + 4];
	nop		0;
	addi	r1 = r0, 111;
	sli		r2 = r1, 8;
	addi	r2 = r2, 222;
	sli 	r3 = r2, 16;
	addi 	r3 = r3, 84;
	swc		[r0 + 1] = r3;
	shc		[r0 + 1] = r2;
	sbc		[r0 + 1] = r1;
	lwc		r4 = [r0 + 1];
	lhc		r5 = [r0 + 1];
	lbc		r6 = [r0 + 1];
	nop 	0;
	swc		[r0 + 2] = r3;
	shc		[r0 + 2] = r2;
	sbc		[r0 + 2] = r1;
	lhuc	r5 = [r0 + 2];
	lbuc	r6 = [r0 + 2];
	halt;