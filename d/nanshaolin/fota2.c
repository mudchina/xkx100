// Room: /d/nanshaolin/fota2.c
// Last Modified by winder on May. 29 2001

#include <ansi.h>
#include <room.h>
inherit ROOM;
string look_wuse();
string look_wuxiang();
string look_kuzhi();
string look_kuhui();
string look_tianming();
string look_huizhi();
void create()
{
	set("short", "圣僧塔");
	set("long", @LONG
本层供奉着少林上代几位有德高僧的灵体法台，塔做六角之形，分
六个方位，六碑上字迹乃是无色台(wuse)，无相牌 (wuxiang)，天鸣禅
台(tianming), 苦智灵碑(kuzhi)，苦慧屏(kuhui)，晦智圣座(huizhi)。
   几缕天光透过塔窗洒在塔内，似乎为千年古塔增添了一点活力。   
LONG );
	set("exits", ([
		"up"   : __DIR__"fota3", 
		"down" : __DIR__"fota1",       
	]));
	set("item_desc",([
		"wuse"     : (: look_wuse :),
		"wuxiang"  : (: look_wuxiang :),
		"tianming" : (: look_tianming :),
		"kuzhi"    : (: look_kuzhi :),
		"kuhui"    : (: look_kuhui :),
		"huizhi"   : (: look_huizhi :),
	]));
	set("no_clean_up", 0);
	set("coor/x", 1750);
	set("coor/y", -6190);
	set("coor/z", 20);
	setup();
}

void init()
{
	add_action("do_say", "say");
	add_action("do_sheshen","sheshen");
	add_action("do_fushi","fushi");
	add_action("do_chuzhang","chuzhang");
	add_action("do_chuzhang","break");
	add_action("do_shenru","shenru");
	add_action("do_taotuo","taotuo");
	add_action("do_canchan","canchan");
	add_action("do_canchan","buddhism");
	add_action("do_enter","enter");
}

int do_say(string arg)
{
	object me = this_player();
// string dir;
	if (arg=="今日大欢喜，舍却危脆身")
	{
		write( "无色禅师的灵台突然旋转起来，发出隆隆声响。一个声音直透你心底，你甘愿为我佛舍身吗？\n");
		me->set_temp("poem_said",1);
		return 1;   
	}
	if (arg=="若得不驰散，深入实相不")
	{
		write("既有此心，何不实施？\n");
		me->set_temp("shen_said",1);
		return 1;
	}
	if (arg=="其心无所乐")
	{
		write("你心中难过，不由得垂下眼，瞑目静思，冥冥中只要逃脱此地。\n");
		me->set_temp("m_said",1);
		return 1;
	} 
}
int do_sheshen()
{
	object me = this_player();
	if(me->query_temp("poem_said"))
	{
		me->delete_temp("poem_said");
		if ((int)me->query_skill("buddhism",1)<30)
		{
			write("你虽有此心，奈何佛法修为太差，反而伤到自己。\n");
			me->unconcious();    
			return 1;
		}
		write( "你口中诵到：“无嗔亦无忧，宁不当欣庆？”身形直向法台撞去，\n只听“砰”的一声，你已被送进了法台。\n");
		me->move(__DIR__"wusetai");
		tell_room(environment(me),me->name()+"一头撞了进来。\n",({me}));
		return 1; 
	}
}
int do_canchan(string arg)
{
	object me = this_player();
	if (arg!="zuo" && arg!="圣座")
		return notify_fail("你要对什么参悟禅理？\n");
	message("vision", me->name()+"对着大师的圣座冥思参禅。\n", environment(me), ({me}) );
	write("你在心中默默念诵“仁者所得法，幸愿示其要。”\n");
	if (random(3)==1)
	{
		write(HIR"你在虚空中，感觉大师座下打开了一个小门。\n" NOR);
		me->set_temp("marks/门",1);
		return 1;
	}
	return 1;
}  
 
int do_enter()
{
	object me = this_player();
	if ((int)this_player()->query_temp("marks/门")) 
	{
		me->delete_temp("marks/门");
		write("你连忙用手扶向小门。\n");
		if ((int)me->query_skill("hand",1)<30)
		{
			write(HIR"你手法太慢，小门已经消失，你头脑中只觉一片昏乱。\n"NOR);
			me->unconcious(); 
			return 1;
		}
		message("vision", me->name()+"双手乱舞，身形飘出，突然消失在圣座下了。\n", environment(me), ({me}) );
		write(HIR"你从小门中走了进去。\n"NOR);
		me->move(__DIR__"huizhizuo");
		tell_room(environment(me), me->name() + "跳了下来。\n", ({me}));
		return 1;
	}  
	return 0;
} 

int do_shenru() 
{
	object me = this_player();
	if(me->query_temp("shen_said"))
	{
		me->delete_temp("shen_said");
		write("你身形一纵，十指如钩，在禅台边上一抓要借力跃起。\n");
		message("vision", me->name()+"身形一纵，十指如钩，在禅台边上一抓要借力纵起。\n", environment(me), ({me}) );
		if((int)me->query_skill("claw",1)<30)
		{
			write("你手指与台边差了寸许，没有抓到。啊.....。\n");
			message("vision", me->name()+"手指与台边还有一定距离，没有抓到。\n", environment(me), ({me}) );
			message("vision", me->name()+"一声大叫，一个倒栽葱摔将下来。\n", environment(me), ({me}) );
			me->unconcious();
			return 1;    
		}
		write( "你在台边一借力，身子凌空直上，落在塔梁上，你脚下一滑，直摔向禅台。\n");
		message("vision", me->name()+"凌空直上，落在塔梁上。突然向下一晃，便踪迹皆无。\n", environment(me), ({me}) );
		me->move(__DIR__"tianming");
		tell_room(environment(me), me->name() + "摔了下来。\n", ({me}));
		return 1;
	}
	return 0;   
}

int do_taotuo()
{
	object me = this_player();
	if (me->query_temp("m_said"))
	{
		me->delete_temp("m_said");
		message("vision", me->name()+"两腿连环踢出，身形跃向塔窗便要逃出。\n", environment(me), ({me}) );
		if ((int)me->query_skill("leg",1)<30)
		{
			write("你两腿已经麻木了，被定在当地。\n");
			return 1;
		} 
		message("vision", me->name()+"身子一下消失在窗边。\n", environment(me), ({me}) );
		write(HIR "你刚到窗边，只觉眼前一黑，便跌将落去。\n"NOR);
		me->move(__DIR__"kuhuiping");
		tell_room(environment(me), me->name() + "跳了下来。\n", ({me}));
		return 1;
	}  
	return 0;
}

int do_fushi(string arg)
{
	object me = this_player();
	if (arg!="pai"&&arg!="牌") return notify_fail("你要拂拭什么？\n");
	message("vision", me->name()+"轻轻地在无相牌上拭去尘土。\n", environment(me), ({me}) );
	write("你轻轻地拂拭无相牌。\n");
	if (random(2)==1)
	{
		write(HIR"你突然有一种出掌的冲动，便想一掌击出。\n"NOR);
		me->set_temp("marks/拍",1); 
	}
	return 1;
}

int do_chuzhang(string arg)      
{
	object me = this_player();     
	if ((int)me->query_temp("marks/拍"))
	{
		if(arg!="pai" && arg!="牌")
			return notify_fail("你要哪出掌？\n");
		me->delete_temp("marks/拍");               
		if ((int)me->query("neili",1)>100)
		{
			write(HIR"你气运丹田，嘿的一声向灵牌推出一掌。只听啪的一声，灵牌裂开一道大缝，你纵身向缝隙中跳去。\n"NOR);
			message("vision", me->name()+"气运丹田，嘿的一声向灵牌推出一掌。只听啪的一声，灵牌裂开一道大缝\n", environment(me), ({me})); 
			message("vision", me->name()+"向缝隙直栽进去。一声闷响，无相牌神奇的合好如初。\n" , environment(me), ({me}));
			me->receive_damage("neili",100);
			me->move(__DIR__"wuxiangpai");
			return 1;
		}
		message("vision", me->name()+"啪的推出一掌，但真气不纯，反而伤到自己\n", environment(me), ({me})); 
		me->set("neili",0);
		return 1;
	}
	return 0;
}
                   
string look_wuse()
{
	return "\n"
	"    ※※※※※※※※※※※※※※※※※※※※※※\n"
	"    ※※※※※※※※※※※※※※※※※※※※※※\n"
	"    ※※※※　　　　　　　　　　　　　　※※※※\n"
	"    ※※※※　诸天无云翳，四面皆清明。　※※※※\n"
	"    ※※※※　　　　　　　　　　　　　　※※※※\n"
	"    ※※※※　微风吹香气，众山寂无声。　※※※※\n"
	"    ※※※※　　　　　　　　　　　　　　※※※※\n"
	"    ※※※※　今日大欢喜，舍却危脆身。　※※※※\n"
	"    ※※※※　　　　　　　　　　　　　　※※※※\n"
	"    ※※※※　无嗔亦无忧，宁不当欣庆？　※※※※\n"
	"    ※※※※　　　　　　　　　　　　　　※※※※\n"
	"    ※※※※※※※※※※※※※※※※※※※※※※\n"
	"    ※※※※※※※※※※※※※※※※※※※※※※\n";
}
string look_wuxiang()
{
	return "\n"
        "    ※※※※※※※※※※※※※※※※\n"
	"    ※※※※※※※※※※※※※※※※\n"
	"    ※※※※　　　　　　　　※※※※\n"
	"    ※※※※　身若菩提树，　※※※※\n"
	"    ※※※※　　　　　　　　※※※※\n"
	"    ※※※※　心如明镜台。  ※※※※\n"
	"    ※※※※　　　　　　　　※※※※\n"
	"    ※※※※　从今勤拂拭，　※※※※\n"
	"    ※※※※　　　　　　　　※※※※\n"
	"    ※※※※　不令惹尘埃。　※※※※\n"
	"    ※※※※　　　　　　　　※※※※\n"
	"    ※※※※※※※※※※※※※※※※\n"
	"    ※※※※※※※※※※※※※※※※\n";
}
string look_tianming()
{
	return "\n"
        "    ※※※※※※※※※※※※※※※※\n"
	"    ※※※※※※※※※※※※※※※※\n"
	"    ※※※※　　　　　　　　※※※※\n"
	"    ※※※※　既已舍染乐，　※※※※\n"
	"    ※※※※　　　　　　　　※※※※\n"
	"    ※※※※　心得善摄不？  ※※※※\n"
	"    ※※※※　　　　　　　　※※※※\n"
	"    ※※※※  若得不驰散，　※※※※\n"
	"    ※※※※　　　　　　　　※※※※\n"
	"    ※※※※　深入实相不？　※※※※\n"
	"    ※※※※　　　　　　　　※※※※\n"
	"    ※※※※※※※※※※※※※※※※\n"
	"    ※※※※※※※※※※※※※※※※\n";
}
string look_kuhui()
{ 
	return "\n"
        "    ※※※※※※※※※※※※※※※※\n"
	"    ※※※※※※※※※※※※※※※※\n"
	"    ※※※※　　　　　　　　※※※※\n"
	"    ※※※※  毕竟空相中，  ※※※※\n"
	"    ※※※※　　　　　　　　※※※※\n"
	"    ※※※※　其心无所乐？  ※※※※\n"
	"    ※※※※　　　　　　　　※※※※\n"
	"    ※※※※  若悦禅智慧，　※※※※\n"
	"    ※※※※　　　　　　　　※※※※\n"
	"    ※※※※　是法性无照。　※※※※\n"
	"    ※※※※　　　　　　　　※※※※\n"
	"    ※※※※※※※※※※※※※※※※\n"
	"    ※※※※※※※※※※※※※※※※\n";
}
string look_huizhi()
{
	return "\n"
        "    ※※※※※※※※※※※※※※※※\n"
	"    ※※※※※※※※※※※※※※※※\n"
	"    ※※※※　　　　　　　　※※※※\n"
	"    ※※※※  虚诳等无实，  ※※※※\n"
	"    ※※※※　　　　　　　　※※※※\n"
	"    ※※※※　亦非停心处。  ※※※※\n"
	"    ※※※※　　　　　　　　※※※※\n"
	"    ※※※※  仁者所得法，　※※※※\n"
	"    ※※※※　　　　　　　　※※※※\n"
	"    ※※※※　幸愿示其要。　※※※※\n"
	"    ※※※※　　　　　　　　※※※※\n"
	"    ※※※※※※※※※※※※※※※※\n"
	"    ※※※※※※※※※※※※※※※※\n";
}
string look_kuzhi()
{
	return "\n"
 	"    ※※※※※※※※※※※※※※※※※※※※※※\n"
	"    ※※※※※※※※※※※※※※※※※※※※※※\n"
	"    ※※※※　　　　　　　　　　　　　　※※※※\n"
	"    ※※※※　一切恩爱会，皆由因缘合。　※※※※\n"
	"    ※※※※　　　　　　　　　　　　　　※※※※\n"
	"    ※※※※　会合有别离，无常难得久。　※※※※\n"
	"    ※※※※　　　　　　　　　　　　　　※※※※\n"
	"    ※※※※　今我为尔母，恒恐不自保。　※※※※\n"
	"    ※※※※　　　　　　　　　　　　　　※※※※\n"
	"    ※※※※　生死多畏惧，命危于晨露。　※※※※\n"
	"    ※※※※　　　　　　　　　　　　　　※※※※\n"
	"    ※※※※※※※※※※※※※※※※※※※※※※\n"
	"    ※※※※※※※※※※※※※※※※※※※※※※\n";
}
