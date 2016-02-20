// Room: /d/yanziwu/langfang.c
// Date: Jan.28 2000 by Winder

inherit ROOM;

void create()
{
	set("short", "琅缳玉洞");
	set("long", @LONG
这里就是武林中人皆欲一至的蔓陀山庄的琅缳玉洞。洞中收藏着当
年逍遥子和他的师妹李秋水收藏的普天下各门各派的武功秘籍。逍遥子
因门派变故，秋水伊人远嫁西夏后，这些典籍被他们的女儿，蔓陀山庄
庄主从无量山琅缳玉洞千里迢迢运抵姑苏，就藏在这个山洞之中。洞侧
天窗一道，天窗外一线天光照着满洞中都是书架，架上摆满了颜色古旧
的书籍，架上均贴有标签(sign)。
LONG );
	set("exits", ([
		"out"    : __DIR__"dong8",
	]));
	set("item_desc", ([
		"sign" : "签上标着少林、武当、青城、大理等门派的名称。\n" 
	]));
	set("objects", ([
		__DIR__"book/axe_book" : random(2),
		__DIR__"book/club_book" : random(2),
		__DIR__"book/hook_book" : random(2),
		__DIR__"book/whip_book" : random(2),
		__DIR__"book/staff_book" : random(2),
		__DIR__"book/stick_book" : random(2),
		__DIR__"book/spear_book" : random(2),
		__DIR__"book/sword_book" : random(2),
		__DIR__"book/blade_book" : random(2),
		__DIR__"book/hammer_book" : random(2),
		__DIR__"book/dagger_book" : random(2),
		__DIR__"book/throwing_book" : random(2),
	]));
	set("coor/x", 1190);
	set("coor/y", -1270);
	set("coor/z", -2);
	setup();
	replace_program(ROOM);
}

