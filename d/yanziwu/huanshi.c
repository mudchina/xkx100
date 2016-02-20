//ROOM: /d/yanziwu/huanshi.c

inherit ROOM;

void create()
{
	set("short", "还施水阁");
	set("long",@LONG
这里就是武林中人人心仪的慕容家藏书之所。天下习武之人，凡闻
“以彼之道，还施彼身”之名者，莫不希望来此，发掘慕容世家绝技的
秘密。阁中满是书架，架上摆着许多颇为古旧的书籍，架上均贴有标签
(sign)。这就是慕容世家历经数代才收集积累而成的武学宝库。
LONG );
	set("exits", ([
		"north": __DIR__"jiashan",
	]));
	set("objects", ([
		__DIR__"book/leg_book": random(2),
		__DIR__"book/cuff_book": random(2),
		__DIR__"book/claw_book": random(2),
		__DIR__"book/hand_book": random(2),
		__DIR__"book/dodge_book": random(2),
		__DIR__"book/finger_book": random(2),
		__DIR__"book/strike_book": random(2),
		__DIR__"book/unarmed_book": random(2),
	]));
	set("item_desc",([
		"sign" : "签上标着少林、武当、青城、大理等门派的名称。\n"
	]));
	set("no_clean_up", 0);
	set("coor/x", 840);
	set("coor/y", -1541);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
