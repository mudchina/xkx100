// /d/taohuacun/caidi2.c
// Last Modifiedy by Zeratul June 2000

#include <ansi.h>
inherit  ROOM;

void harvest( object me, int times );

string  name = "", guarder = "", sort;

void  create()
{
	set("short","菜地");
	set("long", @LONG
这是乡下路边的一块菜地，地里杂草从生，好象已经荒废很久了。
地边有个给守菜地的人挡风雨的小棚子。
LONG
);
	set("exits", ([
		"west" : __DIR__"road1",
	]));
        set("outdoors", "taohuacun");
	set("coor/x", -80);
	set("coor/y", 0);
	set("coor/z", 0);
	setup();
}

void init()
{
	add_action("do_seed", "zhong");
	add_action("do_seed", "seed" );
	add_action("do_guard", "observe");
	add_action("do_guard", "shou");
}

int do_seed(string arg)
{

	object  ob, me = this_player();

	if ( name != "" && name != me->query( "id" ) )  return notify_fail( "这块菜地已经有人种了。\n" );
	if ( name == me->query( "id" ) )  return notify_fail( "你已经在种菜了。\n" );
	if ( !arg || ( arg != "baicai seed" && arg != "qingcai seed" ) )  
		return notify_fail( "你要种什么？\n" );
	if ( !objectp( ob = present( arg, me ) ) )
		return notify_fail( "你没有这种菜种。\n" );
	if ( environment(me)->query("short") != "菜地" )
		return notify_fail( "只有在菜地才能种菜。\n" );
	if ( me->is_busy() )
		return notify_fail( "你现在没空种菜。\n" );
	if ( me->query("qi") < 30 )
		return notify_fail( "你太累了，歇一会儿再种吧。\n" );
	me->add( "qi", -30 );
	message_vision( "$N举起锄头把菜地上的杂草都锄尽了，然后笨手笨脚地把" + ob->query("name") + "种下。\n", me );		
	sort = explode( arg, " " )[0];
	destruct( ob );
	name = me->query( "id" );
	call_out( "harvest", 5, me, 5 );
	
	return 1;
}

void harvest( object me, int times )
{
	int i;
	object ob;
	string *msg=({
HIW "\n渐渐的起风了，天边飘来一片片乌云，集聚在菜地上空。\n看来要下雨了，赶紧搭个棚子遮一遮吧。\n" NOR,
HIC "\n晨曦微露，一群早起觅食的鸟儿唧唧喳喳地飞来，落在菜地里。\n快把它们赶走吧。\n" NOR,		
HIY "\n有几株菜苗耷拉着发黄的叶子，好象得病了，得捉一捉虫了。\n" NOR,
HIG "\n绿油油的菜苗在微风中向你点头。\n看来这次一定是个大丰收，你不禁喜上眉梢。\n" NOR,
	});
	
	if ( times-- > 0 ) {
		i = random(4);
		write( msg[i] );
		if ( i < 3 )
			call_out( "gain", 5, me, i, times );
		else   	call_out( "harvest", 10, me, times );
	}
	else {
		ob = new( __DIR__"npc/obj/" + sort );
		ob->move( me );
		message_vision( HIG "\n$N收获了一筐" + ob->query("name") + "！\n" NOR, me );		
		name = "";
		guarder = "";
	}
}

void gain( object me, int i, int times )
{
	string *fail_msg=({
WHT "你还没凑齐搭棚子的材料，滂沱大雨就已倾盆而下，菜苗都泡在水里了。\n" NOR,		
CYN "你东奔西跑地赶鸟，可是这边赶走了几只，那边又来了一群。不一会儿菜苗就被啄光了。\n" NOR,
YEL "你一时想不出对付虫子的办法，只能眼睁睁看着菜苗被一点一点吃掉。\n" NOR,
	});
	string *suc_msg=({
HIW "你手脚麻利地找到绳子和木头，三下五除二搭好棚子，再大的雨也不怕了。\n" NOR,
HIC "你扎了几个稻草人插在菜地里，鸟儿吓得都飞走了。\n" NOR,
HIY "你采了一些药草在田边烧起来，虫子都被熏死了。\n" NOR,		
	});

	if ( !stringp(guarder) || guarder != me->query("id") || random( me->query("kar") ) < 5 ) {
		write( fail_msg[i] );
		message_vision( WHT "\n菜苗都死光了，$N的辛苦白费了。\n" NOR, me );
		name = "";
		guarder = "";		
	} 
	else {
		write( suc_msg[i] );
		call_out( "harvest", 3, me, times );
	}
		
}

int do_guard()
{
	object me = this_player();
	
	if ( me->query("id") != name )
		return notify_fail( "你不是这个菜地的主人，不必守菜地。\n" );
	if ( me->query("id") == guarder )
		return notify_fail( "你已经在守菜地了。\n" );
	write( "你开始守菜地。\n" );
	guarder = name;
	return 1;
}
	
int valid_leave( object me, string dir )
{
	if ( guarder == me->query( "id" ) )
		return notify_fail( "你正在守菜地，不能离开。\n" );
	return 1;
}

void reset()
{
	if ( !present( name, this_object() ) )
		name = "";
	::reset();		
}	
