// Room: /city/chenglou.c
// Last Modified by winder on Apr. 10 2000

#include <room.h>

inherit ROOM;
string look_yangzhou();
string yangzhou_map = @TEXT
                                             大驿道 古邗沟边-古邗沟边-古邗沟边
                                               ｜  ／
         堂屋 魁星阁         <瘦西湖> <黄河>-镇淮门  <崇雅书院>    |~~|
          ｜       ＼          |｜|            ｜        ｜        |~~|
       资政书院------草河北街--虹桥---------北门大街---琼花街-----开明桥-<东城>
                   ／   ｜     |~~|            ｜        ｜        |~~|
              忠烈祠    ｜     |~~|  小宝斋-十里长街--富春茶社     |小|
                        ｜     |草|            ｜                  |秦|
      <桃花村>          ｜     |河|广陵当铺-十里长街-<淮扬赌场>    |淮|
         ｜             ｜     |~~|            ｜                  |河|
         ｜ <扬州官衙>  ｜     |~~|  <武庙>-十里长街--<醉仙楼>     |~~|
         ｜     ｜      ｜     |~~|            ｜        ｜        |~~|
<洛阳>-通泗门-通泗街-草河小街-通泗桥--------十里长街---甘泉街-----宁海桥-<东城> 
              ／   ／   ｜     |~~|            ｜        ｜        |~~|
   <财主家> ／ <武道场> ｜     |~~|彦明钱庄-十里长街-<秦淮客寓>    |~~|
      ｜  ／            ｜     |~~|            ｜                  |小|
  小草河侧巷-玉器店     ｜     |官|  杂货铺-十里长街-药铺  堂屋    |秦|
    ／   ＼             ｜     |河|            ｜           ｜     |淮|
成衣店 维扬花店-<禅智寺>｜     |~~|  打铁铺-十里长街-武馆 容膝园   |河|
                     ＼ ｜     |~~|            ｜           ｜     |~~|
        <小玲珑山馆>-草河南街-太平桥--------南门大街------禾嘉街-小东门桥-<东城>
                        ｜     |~~|            ｜           ｜     |~~|
                       何园    |~~|          安定门      <城守署>  |~~|
                        ｜     |~~|            ｜         -        |~~|
                     何园后院  |~~|~~~~~~~~~|渡江桥|~~~~~~~~~~~~~~~|~~|
                               ^~~^~~~~~~~~~^  ｜  ^~~~~~~~~~~~~~~~^~~^

TEXT;

void create()
{
	set("short", "镇淮门城楼");
	set("long", @LONG
沿着城门边上的的石阶拾级而上，上得城墙。城墙上建一座城楼，
飞檐高挑，极为雄伟，边上是敌楼，几个士兵在警戒。城楼上有几个游
人，有的在俯视整个扬州城，有的远眺北面的平山堂。
LONG );
	set("exits", ([
		"down"    : __DIR__"beimen",
	]));
	set("item_desc", ([
        "扬州" : (: look_yangzhou :),
        "yangzhou" : (: look_yangzhou :),
        "city" : (: look_yangzhou :),
        "扬州城" : (: look_yangzhou :),
        "平山堂" : "平山堂笼罩在云烟之中，据说知州常在那里饮酒作乐。\n"
	]));
	set("no_clean_up", 0);
	set("outdoors", "yangzhouw");
	set("coor/x", 10);
	set("coor/y", 100);
	set("coor/z", 10);
	setup();
}

string look_yangzhou()
{
	object me = this_player();
	object room;
//	write( yangzhou_map );
	me->start_more(yangzhou_map);
	me->add_temp("yangzhou_look", 1);
	if (random(5) > 2 && me->query_temp("yangzhou_look") )
		write("\n\n你仿佛看到些什么，却有没看清楚。\n");
	else if (random(5) > 2 && me->query_temp("yangzhou_look") > 2 )
		write("\n\n你好象看到了一些东西，却始终没看明白。\n");
	else if (random(5) > 2 && me->query_temp("yangzhou_look") > 5 )
	{
		write("你发现扬州官衙里有个人在蹿来跃去的。\n");
		return "";
	}
	if ( (int)me->query_temp("yangzhou_look") > 3 && random(3) == 0)
	{
		message("vision", "你伸长脖子，探出去想看的更清楚一点，却一不小心掉了下去！\n", me);
		message("vision", "只见"+me->name()+"身子过多的挂出城墙外，双手摇摇了，想控制住平衡，\n终究没有成功，一个倒栽葱掉了下去。\n", environment(me), ({me}));
		if( !room = find_object(__DIR__"beimen") )
			room = load_object(__DIR__"beimen");

		if( room = find_object(__DIR__"beimen") )
		{
			message( "vision", "只见一团黑影从天而降，原来是" + me->name() + "从城墙上掉了下来!\n", room );
			me->move( room );
			if ( me->query_skill("dodge", 1) < 20 ) me->unconcious();
			else if ( me->query_skill("dodge", 1) < 40 )
				tell_object(me,"你尽力在空中控制自己的姿势，还是屁股着地。\n");
			else
				tell_object(me,"你在空中一翻身，轻巧自如的落在地面。\n");
		}
	}
	return "";
}

int valid_leave(object me, string dir)
{
	if ( me->query_temp("yangzhou_look") )
		me->delete_temp("yangzhou_look");
	return ::valid_leave(me, dir);
}