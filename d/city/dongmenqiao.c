// Room: /yangzhou/dongmenqiao.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","小东门桥");
	set("long",@LONG
小东门桥由青石筑成，桥面光滑平整，据说是前朝所建，年代久远。
河中心的桥墩上爬满了青苔，青青的河水从桥下悠然流过，滋润着青苔，
孕育了扬州。你站在桥上，看着小秦淮河两边的密密的屋檐，听着偶尔
传出的儿童的嬉笑声，你感受到扬州悠闲的一面。
LONG );
	set("outdoors", "yangzhouw");

	set("exits", ([
		"west"  : __DIR__"hejiajie",
		"east"  : __DIR__"jiaowai7",
	]));
	set("objects", ([
		"/d/village/npc/boy": random(5),
	]));
	set("coor/x", 30);
	set("coor/y", -50);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}