// Room: /d/wuyi/shuiliandong.c
// Last modified by Winder on Mar.20.2002

inherit ROOM;

void create()
{
	set("short", "水帘洞");
	set("long", @LONG
水帘洞景区在天心岩北两里处，又名唐曜洞天，是武夷山最大的洞
穴，高、宽各三十丈许，上凸下凹，似斜覆的飞檐，崖内轩爽敞亮，有
三祀祠，奉祀宋朝大儒刘子翬（朱熹老师）、朱熹、刘珙。洞前有两道
流淌的清泉，从三十丈米高的崖顶飘洒而下，宛若珠帘，散落在崖下浴
龙池中，人称“赤壁千寻睛疑雨，明珠万颗画垂帘。”，“水帘知丈垂
丹壑，睛雪长年舞翠檐。”《武夷山志》称其为“山中最胜之境”。徐
霞客称其：“危崖千仞，上突下嵌，泉从岩顶堕下，岩既雄旷，泉亦高
散，千条万缕，悬空倾泻，亦大观也”洞内岩壁上有许多摩崖石刻，篆
书“活源”二字，尤为引人注目。
LONG );
	set("outdoors", "wuyi");
	set("no_clean_up", 0);
	set("exits", ([
		"south" : __DIR__"path15",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1400);
	set("coor/y", -4880);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

