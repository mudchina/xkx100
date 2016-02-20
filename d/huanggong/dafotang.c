// Room: /d/huanggong/dafotang.c

inherit ROOM;

void create()
{
	set("short", "大佛堂");
	set("long", @LONG
这是慈宁宫后的大佛堂。堂里供着一尊如来佛像，佛像前是一张供
桌。桌上点着盏油灯。
LONG );
	set("exits", ([
  		"south" : __DIR__"cininggong",
	]));
	set("objects", ([
  		__DIR__"npc/maodongzhu": 1,
  		__DIR__"npc/liuyan": 1,
	]));
	set("coor/x", -220);
	set("coor/y", 5272);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}