// Feb. 6, 1999 by Winder
#include <room.h>
#include <ansi.h>
inherit ROOM;
int do_climb(string arg);
void create()
{
    set("short", "温宅大门");
    set("long", @LONG
这里就是浙南石梁温家的大门，门口两个大石狮，威武异
常，大门紧锁着，门上的铜环却亮得刺眼。围墙很高，门匾上
写着两个烫金的大字“温府”，果然气度不凡。门的旁边有一
株参天大树(tree),人站在下面很是凉快。
LONG
    );
	set("no_clean_up", 0);
	set("outdoors","shiliang");
	set("exits", ([
		"south" : __DIR__"road1",
	]));
	set("item_desc", ([
	"tree": "这是一株上百年龄的老树，枝叶依然十分茂盛，看来是爬不上去的。\n"
	]) );
	set("coor/x", 1610);
	set("coor/y", -1970);
	set("coor/z", 10);
	setup();
}
void init()
{
    object book, me;
    me = this_player();
    add_action("do_climb", "climb");
}
int do_climb(string arg)
{
    int n;
    n = this_player()->query_skill("dodge");
    if( !arg || arg!="tree" ) {
        write("不要到处乱爬！\n");
        return 1;
    }
    message_vision(
    "$N在古树前深深地吸了口气，猛地跃了起来。\n", this_player());
        
    if (n>=80) {
        message_vision("只见$N足尖在树枝上一点，飞身跃过高墙，已悠然飘落院中。\n", this_player());
        this_player()->move(__DIR__"yuanzi");
    }
    else if (n>=50) {
        message_vision(
        "只见$N双手在树上一攀，勉强翻过围墙，跌落院中。\n", this_player());
        this_player()->move(__DIR__"yuanzi");
    }
    else {
        message_vision(
        "$N高高跃起，可还差一大截呢，看来是轻功不够好。\n", this_player());
     }
    return 1;
}