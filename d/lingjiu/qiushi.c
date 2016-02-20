//ROOM qiushi.c

inherit ROOM;
void create()
{
	set("short", "囚室");
	set("long",@LONG
这是『灵鹫宫』关押犯人的地方，屋中光线昏暗，气味难闻。屋角
隐隐约约有个人影。
LONG );
	set("exits", ([
		"east" : __DIR__"men1",
	]));
	set("objects",([
		__DIR__"npc/wulaoda" : 1,
	]));
	set("coor/x", -51050);
	set("coor/y", 30160);
	set("coor/z", 70);
	setup();
	replace_program(ROOM);
}