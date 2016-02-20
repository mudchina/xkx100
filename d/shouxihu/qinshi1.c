// Room: /yangzhou/qinshi1.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","琴室");
	set("long",@LONG
琴室面南三楹，临湖而筑，外嵌“琴室”石额。东侧设小门通观自
在亭。两山开方窗，中悬包契常书“琴室”横匾，外柱悬挂楹联(lian)。
此室为游客品茗佳处，东南檐角挑一“茶”字枋。
    室前栽有两株百年古柏。此处腊梅为湖上一绝，霜降时绿叶未落即
暗香四溢，直至春节仍繁花朵朵，为腊梅珍品。
LONG );
	set("outdoors", "shouxihu");
	set("item_desc", ([
		"lian" : "
        一        画
        水        船
        回        来
        环        往
        杨        藕
        柳        花
        外        天
\n",
	]));
	set("exits", ([
		"northwest"  : __DIR__"changchunling",
		"southeast"  : __DIR__"zizaiting",
		"north"      : __DIR__"qishi",
	]));
	set("no_clean_up", 0);
	set("coor/x", 20);
	set("coor/y", 100);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}