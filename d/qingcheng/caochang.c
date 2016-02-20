// Room: /qingcheng/caochang.c
// Date: Aug. 10 1998 by Winder

inherit ROOM;
void create()
{
	set("short", "练功操场");
	set("long", @LONG
这里是青城弟子练功习武之所，“冬练三九、夏练三伏”，出家人
往往勤快一些，往往天光才有鱼肚白，这里就有练功的影子。到得日出
山坳，便是满场的人声了。
LONG );
	set("outdoors", "qingcheng");
	set("exits", ([
		"east"  : __DIR__"zoulang2",
		"west"  : __DIR__"zoulang3",
		"south" : __DIR__"zoulang1",
		"north" : __DIR__"songfengguan",
	]));
	set("objects", ([
		"/d/shaolin/npc/mu-ren" : 5,
		__DIR__"npc/fang" : 1,
		__DIR__"npc/dizi" : random(4),
	]));
	set("coor/x", -8080);
	set("coor/y", -840);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}