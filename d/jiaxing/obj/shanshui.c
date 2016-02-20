// shanshui.c
// Last Modified by winder on Nov. 17 2000

inherit ITEM;

int do_jiao(string arg);

void create()
{
        set_name("山水画", ({ "shanshui hua", "shanshui", "hua" }) );
	set("long","
只见画中是一座陡峭突兀的高山，共有五座山峰，中间一峰尤高，
笔立指天，耸入云表，山侧生着一排松树，松梢积雪，树身尽皆向南弯
曲，想见北风之烈。峰西独有一棵老松，却是挺然直起，巍巍秀拔，树
下朱笔画着一个迎风舞剑的将军。这人面目难见，但衣袂飘举，资形脱
俗。全幅画都是水墨山水，独此人殷红如火，更加显得卓荦不群。画上
并无书款，只题着一首诗云：“经年尘土满征衣，特特寻芳上翠微，好
山好水看不足，马蹄催趁月明归。”
");
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "幅");
        }
        setup();
}

void init()
{
	add_action("do_jiao","water");
	add_action("do_jiao","jiao");
}

int do_jiao(string arg)
{
	object me=this_player();
	object* inv;
	int i, remaining;

	if (!id(arg)) return 0;
	inv = all_inventory(me);
	for (i = 0; i < sizeof(inv); i++) {
		if (mapp(inv[i]->query("liquid"))) {
			if ((remaining = inv[i]->query("liquid/remaining")) > 0) {
				write("你从" + inv[i]->query("name") + "里倒出些" + inv[i]->query("liquid/name") + "来，涂在画上。\n");
				write("忽见画的右下角依稀露出几行字迹：“..穆遗书，..铁掌..，中....峰，第二..节。”\n");
				me->set_temp("wumu_shanshui", 1);
				remaining--;
				inv[i]->set("liquid/remaining",remaining);
				return 1;
			}
			else {
				write("你的" + inv[i]->query("name") + "已经空了，再也挤不出一滴" + inv[i]->query("liquid/name") + "了！\n");
				return 1;
			}
		}
	}
	write("你的身上没有带盛水的器具！\n");
	return 1;
}
