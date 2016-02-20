//TORJQ2.C

inherit ROOM;

void create()
{
	set("short", "青石大道");
	set("long", @LONG
这里大道平坦，地势开阔，两旁树林中鸟语花香，一片和平安祥的
气氛。此时又有谁能想到，这条大道上撒下过多少江湖中人的血，这片
林中又埋有多少惨死于武林争斗的冤魂的骨。远处，隐约传来叮叮咚咚
的伐木声，偶尔能让人追忆起刀戈铁马的沙场景象。
LONG );
	set("exits", ([
		"northwest" : __DIR__"tojmq3",
		"southeast" : __DIR__"tojmq1",
	]));
	set("no_clean_up", 0);
	set("outdoors", "mingjiao");
	set("coor/x", -52050);
	set("coor/y", 850);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}