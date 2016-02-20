// /d/meizhuang/xiaowu.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;

void create()
{
	set("short", "内室");
	set("long", @LONG
室内一床一几，陈设简单，床上挂了的纱帐，铺着的被褥，均甚是
陈旧，已呈黄色。几上放着一张短琴，通体黝黑，似是铁制。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"south" : __DIR__"xiaowu",
	]));
	set("item_desc", ([
		"chuang" : "这是一张很陈旧的木床。\n" ,
		"床"     : "这是一张很陈旧的木床。\n" ,
		"beiru"  : "这是一床铺在床上的旧被褥。\n" ,
		"被褥"   : "这是一床铺在床上的旧被褥。\n" ,
	]));
	set("coor/x", 3510);
	set("coor/y", -1410);
	set("coor/z", 20);
	setup();
}

void init()
{
        add_action("do_move", "xian");
        add_action("do_move", "move");
        add_action("do_open", "open");
        add_action("do_open", "ti");
}
int do_move(string arg)
{
	object me = this_player();

	if (!arg||arg!="beiru") return notify_fail("你要掀开什么？\n");
	if ( query("beiru") )
		return notify_fail("被褥已经掀开了，再掀就掉地上了！\n");
	message_vision("$N掀开床上被褥，揭起床板，下面却是块铁板，上有铜环。\n", me);
	set("beiru", 1);
	return 1;
}

int do_open(string arg)
{
	object midao1, me = this_player();

	if (!arg||arg!="tieban") return notify_fail("你要提开什么？\n");
	if (me->query("neili") < 200)
	{
		message_vision("$N握住铜环，向上一提，铁板纹风不动。\n", me);
		me->set("neili", 0);
		return 1;
	}
	me->add("neili", -200);
	if(!( midao1 = find_object(__DIR__"midao1")) )
		midao1 = load_object(__DIR__"midao1");
        if(objectp(midao1))
        {
		set("exits/down", __DIR__"midao1");
		message_vision("$N握住铜环，向上一提，一块四尺来阔、五尺来长的铁板应手而起，露出一个长大方洞。\n", me);
		midao1->set("exits/up", __FILE__);
                message("vision","头上透出一点光，好象是上面有人打开铁板了。\n", midao1);
                remove_call_out("close_gate");
                call_out("close_gate", 5);
        }
	return 1;
}
void close_gate()
{
	if( !query("exits/down") ) return;
	message("vision","铁板落下来, 将洞口遮得严严实实的。\n", this_object());
	delete("exits/down");
}



