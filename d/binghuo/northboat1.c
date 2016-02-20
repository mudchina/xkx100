// Room: /binghuo/boat1.c
// Date: Oct.28 1999 by Winder
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "帆船");
	set("long", @LONG
这是一艘三桅海船，不知船主是谁。船上前后两桅挂了白帆，准
备出海。船中舱中备有粮水，足够支用半年。船上水手个个都是哑巴。
主桅(gui) 空悬一条缆绳，随风不住舞动。
LONG );
	set("outdoors", "lingshe");
	set("item_desc", ([
		"gui" : "海船上的主桅，可以挂帆。\n",
	]));
	set("exits", ([
		"out" : __DIR__"lingshegang",
	]));
	setup();
}

void init()
{
	add_action("do_gua", "gua");
	add_action("do_gua", "hang");
}
int do_gua ( string arg )
{
	object ob ;
	string dir;
	if( !arg || (arg !="fan" && arg != "fan bu")) 
	{
		tell_object(this_player() , "你要挂啥呢？瞎折腾！\n" ) ;
		return 1 ;
	}
	ob = this_player ();
	if (!(present("fan bu", ob)))
	{
		tell_object(this_player() , "帆布在哪？你四下一望，没见着！\n");
		return 1 ;
	}
	message_vision("$N挂起主帆，船头缓缓转过，向北航行。\n", ob);
	ob ->move(__DIR__"northboat2") ;
	tell_object(ob, BLU "海风一阵阵从舱口中吹了进来，你感到阵阵寒意.......\n" NOR ) ;
	call_out("north1", 10 , ob );
	return 1 ;
}
void north1( object ob )
{
	tell_object(ob , BLU
"突然之间，你身子一侧，滚了几个转身，但听得水手同时大叫，
呼喝声中又夹着疾风呼啸，波浪轰击之声，似乎千百个巨浪同
时袭到。你只感全身一凉，口中鼻中全是盐水，当即挣扎着站
起。脚底下舱板斗然间向左侧去，船中的海水又向外倒泻，但
听得狂风呼啸，身周尽是海水。
    但听喀喇喇、喀喇喇几声猛响，主桅和前桅先后折断。两
条桅杆带着白帆，跌入海中。\n" NOR);
	ob->move (__DIR__"northboat3") ;
	tell_object(ob , BLU
"又是一个浪头扑将上来，这巨浪犹似一堵结实的水墙，砰的一
声大响，只打得船木横飞。\n" NOR) ;
	if (ob->query("neili") < 300)
	{
		tell_object(ob , HIR
"\n蓦地里一个巨浪飞到，将你冲出船舷之外。这个浪头来得极其
突兀，你全然的猝不及防。待得惊觉，已是身子凌空，这一落
下去，脚底便是万丈洪涛......\n" NOR) ;
		ob->unconcious();
		ob->move("/d/quanzhou/haigang");
	}
	else call_out("north2", 10 , ob);
}
void north2( object ob )
{
	tell_object(ob , BLU
"船上的舱盖、甲板均被打得破碎不堪，船身却仍无恙。头顶乌
云满天，大雨如注，四下里波涛山立，这当儿根本分不出东南
西北。船身一时如上高山，片刻间似泻深谷，桅樯尽折，船只
也已无法驾驶。\n" NOR);
	ob->move (__DIR__"northboat4") ;
	tell_object(ob , BLU
"海流一直向北，带着船只日夜不停的北驶。夜晚北极星总是在
船头之前闪烁，太阳总是在右舷方升起，在左舷方落下，连续
十余日，船行始终不变。\n" NOR);
	call_out("north3", 10 , ob );
}
void north3( object ob )
{
	tell_object(ob , BLU
"气候却一天天的寒冷起来，你也一天比一天憔悴。眼看座船再
北行数日，非冻死你不可。\n"NOR);
	call_out("north4", 10 , ob );
}
void north4( object ob )
{
	tell_object(ob , BLU
"这船日夜不停的向北驶去，越北越冷，此刻海中出现小小碎冰，
日后势必满海是冰，座船一给冻住，移动不得，那便是你毕命
之时了。只是听着丁冬、丁冬，冰块互相撞击的声音，一夜不
寐。\n"NOR);
	call_out("north5", 10 , ob );
}
void north5( object ob )
{
	tell_object(ob , BLU
"次日上午，海上冰块已有碗口大小，撞在船上，拍拍作响。海
面浮冰或如桌面，或如小屋，忽听得轰的一声巨响，船身剧烈
震动。\n" NOR) ;
	if (random(5) > 2)
	{
		ob->move (__DIR__"ice1") ;
		tell_object(ob , BLU
"你被抛在冰山之上，船底撞破的洞孔甚大，只一顿饭时分便已
沉得无影无踪。\n" NOR);
	}
	else
	{
		tell_object(ob , HIY "你被撞得晕了过去......\n" NOR);
		ob->unconcious();
		ob->move ("/d/beijing/haigang");
	}
}
