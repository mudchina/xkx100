// Room: /d/taohua/caodi.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "草地");
	set("long", @LONG
你眼前出现一大片草地，芳草如茵，洒落一地鲜艳的野花。偶尔有
兔鸟飞驰而过，盎然生机一片。草地周遭是密密层层的桃树，阳春三月
之时，郁郁葱葱，一团绿、一团红、一团黄、一团紫，端的是繁花似锦、
芳菲无限。草地之北是一排竹林。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"south" : __DIR__"xiaoyuan",
		"north" : __DIR__"jicui",
	]) );
	set("no_clean_up", 0);
	set("outdoors","taohua");
	set("objects",([
		"/d/wudang/npc/yetu" : 1,
	]));  

	set("coor/x", 9010);
	set("coor/y", -3040);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	object *ob, *deep_ob;
	int i, j, drop_flag;

	if (dir == "west" || dir == "east") {
		if (!me->query_temp("bagua_1") && me->query_skill("qimen-wuxing", 1) < 90)
			return notify_fail("你感觉这个桃花阵中暗藏八卦，隐隐生出阻力，将你推了回来！\n");
		ob = all_inventory(me);
		drop_flag = 0;
		for(i = 0; i < sizeof(ob); i++) {
			if (userp(ob[i])) {
				if (!drop_flag) {
					message_vision("$N看了看眼前这个复杂无比的八卦阵，决定丢下包袱，轻装上阵。\n", me);
					drop_flag = 1;
				}
				message_vision("$N将$n从背上放了下来，躺在地上。\n", me, ob[i]);
				ob[i]->move(this_object());
			}
			else {
				deep_ob = deep_inventory(ob[i]);
				for(j = 0; j < sizeof(deep_ob); j++) {
					if (userp(deep_ob[j])) {
						if (!drop_flag) {
							message_vision("$N看了看眼前这个复杂无比的八卦阵，决定丢下包袱，轻装上阵。\n", me);
							drop_flag = 1;
						}
				                message_vision(sprintf("$N丢下一%s$n。\n", ob[i]->query("unit")), me, ob[i]);
						ob[i]->move(this_object());
						break;
					}
				}
			}
		}
	}

	return ::valid_leave(me, dir);
}