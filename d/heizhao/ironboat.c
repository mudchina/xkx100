// Room: /heizhao/ironboat.c
// Date: Dec. 8 1999 by Winder

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "铁舟");
	set("long", @LONG
这是一艘黑黝黝的小船，舟中放着两柄铁桨，铁舟很小至多只
能乘坐二人。
LONG );
	set("outdoors", "taoyuan");
	set("resource/water", 1);
	set("exits", ([
		"south" : __DIR__"xiaowu",
		"out"   : __DIR__"pububian",
	]));
	set("coor/x", -5020);
	set("coor/y", -1250);
	set("coor/z", 20);
	setup();
}

void init()
{
	object ob = this_player();
	if (ob->query("max_neili") > 1500)
	{
		call_out("upload", 1, ob);
	}
	else
	{
		message_vision(HIR"\n你内力不足，强行解缆非被冲到了边缘
之外，一泻如注，非摔得粉身碎骨不可！\n"NOR, ob);

	}
}

void upload( object ob )
{
	message_vision( BLU
"\n$N举起铁舟，喝一声：“起！”用力掷入瀑布的上游。铁舟
一经掷出，$N立即抢起铁桨，挟在左腋之下，只见铁舟已顺
着水流冲到跟前，涌身前跃，落入舟中。\n\n" NOR, ob);
	ob ->move(__DIR__"ironboat2") ;
	message_vision( HIG
"\n这时水声轰轰，眼见铁舟随着瀑布即将流至山石边缘，$N左
手铁桨急忙挥出，用力一扳，铁舟登时逆行了数尺。
铁桨再是一扳，那舟又向上逆行了数尺。双膀使力，挥桨与
激流相抗。那铁舟翘起了头鼓浪逆行。\n\n" NOR, ob);
	call_out("upload2", 10, ob);
}
void upload2( object ob )
{
	message_vision( HIC
"\n此处水流虽不如瀑布般猛冲而下，却也极是急促，$N划得面
红气促，好几次险些给水冲得倒退下去。"
"\n铁舟向右首转过山角，眼前已非瀑布，乃是一道急流，$N扳
动铁桨，在急湍中逆流而上。\n\n" NOR, ob);
	message_vision( HIG
"\n又行一阵，划过两个急滩，一转弯，眼前景色如画，清溪潺
潺，水流平稳之极，几似定住不动。那溪水宽约丈许，两旁
垂柳拂水，绿柳之间夹植着无数桃树，若在春日桃花盛开之
时，想见一片锦绣，繁华耀眼。这时虽无桃花，但水边生满
一丛丛白色小花，芳香馥郁。\n\n" NOR, ob);
	call_out("upload3", 10, ob);
}
void upload3( object ob )
{
	message_vision( HIG 
"\n$N直瞧得心旷神怡，料想不到这高山之巅竟然别有一番天地。
溪水碧绿如玉，深难见底，溪面水平如镜，底下却有一股无
声的激流。
\n那铁舟缓缓向前驶去，绿柳丛间时有飞鸟鸣啭。铁舟忽然钻
入了一个山洞。洞中香气更浓，水流却又湍急，只听得一阵
眼前斗亮，铁舟已然出洞，洞外是个极大的喷泉，高达二丈
有余，奔雪溅玉，一条巨大的水柱从石孔中直喷上来，飞入
半空，嗤嗤之声就是从喷泉发出。那溪水至此而止，这喷泉
显是下面溪水与瀑布的源头了。\n"NOR, ob);
	call_out("upload4", 10, ob);
}
void upload4( object ob )
{
	message_vision( HIR 
"\n$N起身上岸，将铁舟拉起放在石上，回过头来，却见水柱在
太阳照耀下映出一条眩目奇丽的彩虹。\n\n" NOR, ob) ;
	ob->move (__DIR__"shanlu10");
}