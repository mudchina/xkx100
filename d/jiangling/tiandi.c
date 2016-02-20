//Edited by fandog, 02/18/2000

inherit ROOM;
void create()
{
	set("short", "农田");
	set("long", @LONG
这里是湘西山中的一片农田。山里土地贫脊也没什么可种的，乡下
人家种了些小麦番薯。田里禾秧已长得四寸来高。田梗上插种着大豆和
花生，倒是绿油油的显得比较有生气。
LONG );
	set("exits", ([
		"eastdown"  : __DIR__"tulu3",
		"south"     : __DIR__"maxipu",
	]));
	set("objects", ([
		__DIR__"npc/cow" : 1,
	]));
	set("outdoors", "jiangling");
	set("coor/x", -1610);
	set("coor/y", -2200);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}