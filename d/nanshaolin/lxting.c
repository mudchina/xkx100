// Room: /d/nanshaolin/lxting.c
// Last Modified by winder on May. 29 2001

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", MAG"立雪亭"NOR);
	set("long", @LONG
你沿台阶拾阶而上，眼前出现一座亭子一般的殿堂。殿前横匾上写
着『立雪亭』三个大字。这里又名达摩亭。殿内佛龛供奉达摩铜像和二
祖，三祖，四祖，五祖的立像。相传神光在嵩山本院立雪亭立雪断臂得
授达摩真传衣钵的地方。殿内正中的蒲团上坐着一位白眉白须的老僧。
LONG );
	set("exits", ([
		"north"     : __DIR__"sblu-2",
		"southdown" : __DIR__"taijie",
	]));
	set("objects",([
		CLASS_D("nanshaolin") + "/dayi" : 1,
	]));
	set("outdoors","nanshaolin");
	set("coor/x", 1820);
	set("coor/y", -6160);
	set("coor/z", 20);
	setup();
}

int valid_leave(object me, string dir)
{
	mapping myfam;
	myfam = (mapping)me->query("family");

	if((!myfam || myfam["family_name"] != "南少林派" ||
		myfam["generation"] > 22 ) &&
		objectp(present("dayi dashi", environment(me))) &&
		dir == "north" ) 
	{
		return notify_fail("大痍大师伸手拦住你躬身说道：后面乃是本寺重地，非本派高辈弟子，不能擅入！\n");
	}
	return ::valid_leave(me, dir);
}

