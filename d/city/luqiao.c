// Room: /city/luqiao.c
// Last Modified by Winder on Jul. 15 2000

inherit ROOM;

void create()
{
	set("short", "露桥");
	set("long", @LONG
桥的北头，翼以二亭，名翠阴，名雪芗，半突于水面之上。桥的南
面，湖石山子巍然耸立，气势不同凡响。山顶构一亭，曰诗兴，半掩于
耸峰之后，格外增加了山的层次感。当山峰倒影于水的时候，尤其使人
感觉到水之深和山之伟了。天上的云，如同溶合在水里；水里的鱼，好
似悠游于天半。
LONG );
	set("exits", ([
		"northwest" : __DIR__"qinshi",
		"south"     : __DIR__"hushishandong",
		"southup"   : __DIR__"shixingting",
	]));
	set("outdoors", "yangzhouw");
	set("no_clean_up", 0);
	set("coor/x", -22);
	set("coor/y", 3);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}