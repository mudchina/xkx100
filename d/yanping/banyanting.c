// Room: /d/yanping/banyanting.c
// Date: Sep 28, 2002  Winder

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "半岩亭");
	set("long", @LONG
三千八百坎古趣盎然，山径林荫蔽日，盛夏无暑，蝉鸣鸟语，深旷
幽静。循蜿蜒曲折的石阶而行，途经三个凉亭，以半岩亭最为形胜。半
岩亭往上，地势危岌，左是深壑，右是峭岩，春夏之时瀑布从岩顶飞泻
而下，煞为壮观。延平八景之一的“中岩飞瀑”(pu)即是指此。
LONG );
	set("exits", ([
		"northup"   : __DIR__"gubao",
		"southdown" : __DIR__"3800kan",
	]));
        set("item_desc", ([
                "pu" : 
HIC"        中岩瀑布\n"HIY"                    刘璋(明)"NOR"
飞流一万丈， 界破碧山烟。
醉眼朦胧看， 长虹饮玉川。\n"HIY"
                    廖纪(明)"NOR"
山中有静者， 木食衣草莱。
白杼三千尺， 朝朝浣劫灰。\n"HIY"
                    吴恭(明)"NOR"
银河垂地三千尺， 挂在中岩石壁端。
瀑布倒悬秋色净， 雪花飞坠晓光寒。
谷深信有神龙蛰， 岁旱宁忧海水乾。
更欲携琴来此处， 拟邀庄子共盘桓。
\n",
        ]));
	set("no_clean_up", 0);
	set("outdoors", "yanping");
	set("coor/x", 1500);
	set("coor/y", -6120);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}
