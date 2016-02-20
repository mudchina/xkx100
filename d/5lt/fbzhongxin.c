// Room: /d/5lt/fbzhongxin.c
inherit ROOM;

#include <ansi.h>

string look_board();

void create()
{
	set("short", "新闻发布中心");
	set("long", @LONG
这里是新闻发布中心，所有无厘头电视台的新闻和记者招待会都是
这里第一时间发布出去的。这里金光闪闪的，比起CCTV强多了，对面的
墙上有一个很大的电子通告牌(board)，里头滚动播放着最新的新闻。
LONG);
	set("outdoors", "5lt");
	set("exits", ([
		"west"     : __DIR__"dating",
	]));
	set("item_desc",([
		"board"		:	(: look_board :),
	]));
	set("no_fight", 1);
	set("no_clean_up", 0);
	set("coor/x", -175);
	set("coor/y", 30);
	set("coor/z", 0);
	setup();
}

string look_board()
{
	return
	"※※※※	"HIY"电子公告牌:"NOR"			※※※※\n"
	"※※※※	五月天来厦,秘会绯闻女友。	※※※※\n"
	"※※※※	谣言：据说某人恋爱了。		※※※※\n";
}