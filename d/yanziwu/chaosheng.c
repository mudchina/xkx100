// Room: /d/yanziwu/chaosheng.c
// Date: Jan.28 2000 by Winder

inherit ROOM;

void create()
{
	set("short", "潮声岩");
	set("long", @LONG
潮声岩一半浸没在水中。岩石大可丈许，内里早被波浪掏空。一旦
潮水来时，水波相激，轰然做响，声闻远近。湖浪冲击潮声岩内壁，猛
然反溅回来，你一愣神，不自禁举手想挡(dang)一下。
LONG );
	set("outdoors", "mantuo");
	set("no_clean_up", 0);
	set("exits", ([
		"enter"   : __DIR__"dong2",
	]));
	set("coor/x", 1200);
	set("coor/y", -1280);
	set("coor/z", 0);
	setup();
}
void init()
{
	add_action("do_parry", "dang");
	add_action("do_parry", "parry");
}
int do_parry()
{
	object weapon, me = this_player();
	int skilllvl = me->query_skill("parry",1);
	int exp = me->query("combat_exp");
	if(me->query("qi") < 10)
		return notify_fail("你出手想挡，可是没力气啦，当场水淋满头。\n");
	me->add("qi",-10);
	me->add("eff_qi",-2); 
	if (skilllvl < 50)
		return notify_fail("你出手想挡，可是来不及啦，浪头盖下，浇你个一头湿。\n");
	if (skilllvl > 150)
		return notify_fail("挡什么挡！这点小浪有什么可怕的？\n");
        if (!objectp(weapon = me->query_temp("weapon")))
		return notify_fail("没有用兵器，恐怕挡不住吧？\n");
	if ((skilllvl*skilllvl*skilllvl/10) < exp)
		me->improve_skill("parry", random(me->query_skill("parry",1)));
	return notify_fail("你提起"+ weapon->query("name")+"，向浪头挥去，一股罡气将浪头击得四散溅落。\n");
}
