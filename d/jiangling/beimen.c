//Edited by fandog, 02/18/2000

inherit ROOM;
void create()
{
	set("short", "北门");
	set("long", @LONG
这是荆州北城门。城墙虽然是土制的，却也雄伟壮观。从这里往南
走，就是热闹的荆州西街了。北方是一条黄土路。
LONG );
	set("exits", ([
		"south" : __DIR__"xijie1",
		"north" : __DIR__"tulu",
	]));
	set("objects", ([
		"/d/huashan/npc/haoke" : 1,
		"/d/taishan/npc/dao-ke" : 2,
	]));
	set("outdoors", "jiangling");
	set("coor/x", -1500);
	set("coor/y", -1100);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}