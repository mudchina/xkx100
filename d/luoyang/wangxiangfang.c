//  Room:  /d/luoyang/wangxiangfang.c

inherit  ROOM;

void  create  ()
{
	set("short",  "厢房");
	set("long",  @LONG
这里是王家的厢房。进门处是一扇雕花门，门扇上镂空雕着三国故
事：一边是千里走单骑，正合王家绝技。一边是定军山老黄忠，也是个
刀显威风的场面。房内一张大床，堆着枕席，甚是精洁。房角小几上摆
着茶具，壁上挂着一口单刀。
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"south"  :  __DIR__"wangzhangfang",
		"east"   :  __DIR__"wanghuating",
	]));
	set("objects",  ([  /*  sizeof()  ==  2  */
		__DIR__"npc/wangjiajun" : 1,
	]));
	set("coor/x", -610);
	set("coor/y", 30);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
