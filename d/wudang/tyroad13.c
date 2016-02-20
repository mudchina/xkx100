// tyroad13.c 桃园小路
// by Marz 

inherit ROOM;
#include "feng.h"
string* npcs = ({
	"little_monkey",
	"monkey",
	"little_monkey",
	"little_bee",
	"bee",
	"little_bee",
});
				
void do_tao();
int do_zhai(string arg);
void create()
{
	int i = random(sizeof(npcs));
	    
	set("short", "桃园");
	set("long", @LONG
眼前豁然开朗，你轻松地走在桃园的小路上。两边是桃树林(tree)，
树上盛开着粉红的桃花，红云一片，望不到边。不时有蜜蜂「嗡嗡」地
飞过，消失在在花丛中；几只猴子在树上互相追逐着，叽叽喳喳地争抢
桃子。远处是高高的天柱峰(feng)。
LONG );
	set("outdoors", "wudang");

	set("exits", ([
		"east" : __DIR__"gyroad1",
		"west" : __DIR__"tyroad12",
	]));
	set("item_desc", ([
		"feng" : (:look_feng:),
		"tree" : 
"这是一片桃林，上面结满了水蜜桃，引得人哈喇子都掉下来了。\n"
	]));
	set("objects", ([
		__DIR__"npc/"+npcs[i] : 1
	]));
	set("taocount",2);
	set("coor/x", -1940);
	set("coor/y", -930);
	set("coor/z", 30);
	setup();
}
void init()
{
	add_action("look_feng", "look");
	add_action("do_zhai","zhai");
}

int do_zhai(string arg)
{
	object tao, me = this_player();

	if( !arg || arg=="" )
	{
		message_vision("你想摘什么？\n", me);
		return 1;
	}
	if( arg=="tao"||arg=="taozi" )
	{
		if(query("taocount") > 0)
		{
			message_vision("$N桃树上摘下一个熟透的水蜜桃。\n", me);
			tao = new(__DIR__"obj/mitao");
			tao->move(me);
			add("taocount",-1);
			return 1;
		}
		else
			message_vision("你这么着急呀？桃还没熟呢。\n", me);
		remove_call_out("do_tao");
		call_out("do_tao",60);
		return 1;	     
	}
	return 0;
}
void do_tao()
{
	set("taocount",2);
}
