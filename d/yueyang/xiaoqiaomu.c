// Room: /d/yueyang/xiaoqiaomu.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "小乔墓");
	set("long", @LONG
小乔墓位于岳阳楼东北隅，墓北小庙，内供小乔像，据明《一统志
》载：宾孙策攻皖，得乔公二女，自纳大乔，而以小乔归周瑜，后卒葬
于此。如今青冢草长，蝶飞蜂嬉，玉人如梦了。
LONG );
	set("outdoors", "yueyang");
	set("no_clean_up", 0);
	set("exits", ([
		"southwest" : __DIR__"yueyanglou1",
	]));
	set("coor/x", -1440);
	set("coor/y", -2250);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
