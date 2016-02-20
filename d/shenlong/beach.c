// /d/shenlong/beach.c
// Last Modified by winder on Jul. 12 2002

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "海岸");
	set("long", @LONG
这是神龙岛的出海口，浪花拍打着礁石，发出阵阵响声，海面上一
群群海鸥『欧欧..』地叫着，不时有鱼儿跃出海面，溅起层层的浪花。
边上有艘大船(chuan)， 船上坐着几个船夫打扮的人，乘船可渡过大海
到达海的另一端。东面是神龙岛的海滩。
LONG
	);
	set("outdoors", "shenlong");

	set("exits", ([
		"east" : __DIR__"haitan",
	]));
	set("item_desc", ([
		"chuan" : "这是神龙岛对外联系的大船。岛上的客人或弟子只要\n上船(enter)就可以回中原。\n",
	]));
	set("exits",([
		"east" :__DIR__"haitan",
	]));
	set("outdoors", "shenlong");
	set("coor/x", 4000);
	set("coor/y", 3000);
	set("coor/z", 0);
	setup();
}

void init()
{
	add_action("do_enter", "enter");
}
int do_enter ( string arg )
{
	object ob ;
	string dir;
	if( !arg || arg !="chuan" ) 
	{
		tell_object(this_player() , "你要 enter 哪儿？\n" ) ;
		return 1 ;
	}
	ob = this_player () ;
	message_vision("船夫一见有人上船，忙叫了一声：开船喽！\n", ob);
	message_vision("船夫升起帆，船就向西方航行。\n", ob);
	ob ->move(__DIR__"dahai") ;
	tell_object(ob, BLU "你在海上航行了很久很久.......\n" NOR ) ;
	call_out("home", 10 , ob );
	return 1 ;
}
void home( object ob )
{
	tell_object(ob , "大船终于抵达了中原的一个繁华城市。你走下船来。\n" ) ;
	ob->move ("/d/beijing/haigang") ;
}
