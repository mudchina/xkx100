// Room: /binghuo/wangpangu2.c
// Date: Oct.28 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "山谷");
	set("long", @LONG
四周长满了几百株合抱大松树。左首山峰前一堵大石壁，壁上刻
着廿四字(zi)，纵横开阖，宛如施展拳脚一般。但见笔划多的不觉其
繁，笔划少的不见其陋，其缩也凝重，似尺蠖之屈，其纵也险劲，如
狡兔之脱，淋漓酣畅，雄浑刚健，俊逸处如风飘，如雪舞，厚重处如
虎蹲，如象步。其中两个“不”字，两个“天”字，但两字写来形同
而意不同，气似而神不似，变化之妙，又是另具一功。尤其是“锋”
字最后一笔，直划下来，当真是星剑光芒，如矢应机，霆不暇发，电
不及飞。
LONG );
	set("no_sleep_room",1);
	set("outdoors", "wangpan");
	set("item_desc", ([
		"zi": 
"　　　　※※※※※※※※※※※※※※※※※※※※※※※\n"
"　　　　※※※※　　        　　　　　　　　　※※※※\n"
"　　　　※※※※　　谁　倚　莫　号　宝　武　　※※※※\n"
"　　　　※※※※　　        　　　　　　　　　※※※※\n"
"　　　　※※※※　　与　天　敢　令　刀　林    ※※※※\n"
"　　　　※※※※　　        　　　　　　　　　※※※※\n"
"　　　　※※※※　　争　不　不　天　屠　至　　※※※※\n"
"　　　　※※※※　　        　　　　　　　　　※※※※\n"
"　　　　※※※※　　锋　出　从　下　龙　尊　　※※※※\n"
"　　　　※※※※　　　　　　                　※※※※\n"
"　　　　※※※※※※※※※※※※※※※※※※※※※※※\n",
	]));
	set("exits", ([
		"north"     : __DIR__"wangpangu1",
		"northeast" : __DIR__"wangpanlin",
	]));
	set("objects", ([
		__DIR__"npc/guo" : 1,
		__DIR__"npc/mai" : 1,
		__DIR__"npc/yuan" : 1,
	]));
	setup();
	replace_program(ROOM);
}

