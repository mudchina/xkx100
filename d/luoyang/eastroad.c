//  Room:  /d/luoyang/eastroad.c

inherit  ROOM;

void  create  ()
{
	set("short",  "金谷街");
	set("long",  @LONG
由于连年的战乱，整条金谷街的不少铺子已经荒废掉了只剩下南面
的一家卖牡丹花的店铺。北面石街通往铜驼陌，西面是鼓楼，东面则是
洛阳城的东门。
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"east"  :  __DIR__"eastgate",
		"west"  :  __DIR__"center",
		"south" :  __DIR__"huadian",
		"north" :  __DIR__"xiaojie1",
	]));
	set("objects",  ([
		__DIR__"npc/wangjiaju" : 1,
	]));
	set("outdoors", "luoyang");
	set("coor/x", -400);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
