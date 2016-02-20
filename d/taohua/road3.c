inherit ROOM;
 
void create()
{
	set("short", "小路");
	set("long",@LONG
这是一条通往后山的小径。小路两旁长满了杂草。由于人们很少走
这条路，甚至连路中央也稀稀疏疏冒出了草芽。东边有一个小山洞。
LONG);
	set("exits", ([
		"east"  : __DIR__"dongkou",
		"west"  : __DIR__"road2",
	]));
	set("objects", ([
		__DIR__"npc/dushe": 4,
	]) );
	set("outdoors", "taohua");
//	set("no_clean_up", 0);
	set("coor/x", 9100);
	set("coor/y", -3050);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}