// Room: /d/taishan/daizong.c
// Last Modified by winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "岱宗坊");
	set("long", @LONG
岱宗坊，又名玲珑坊，位于泰安县城以北约一里，坊建于台基上，
四柱三门式，康熙大帝撰书楹联：“峻极于天，赞化体元生万物；帝出
乎震，赫声濯灵镇东方。”此处是登泰山的入口。相传当年碧霞元君被
姜子牙戏弄，诱她投掷绣花鞋以定泰山地界，结果碧霞元君只能把绣花
鞋从山顶掷到此处。从此泰山便以此为起点。
　　坊东丰都庙，祀丰都大帝，配以冥府十王。坊北三皇庙，祀伏羲、
神农、黄帝，配以八蜡神。坊西建封院，宋政和年间改为升元观，祀东
岳福神东华帝君。坊内松柏郁郁，奇石林立，溪泉争流。
LONG );
	set("exits", ([
		"northup" : __DIR__"baihe",
		"south"   : __DIR__"daimiao",
		"west"    : "/d/huanghe/huanghe5",
	]));
	set("objects", ([
		"/quest/shan" :1,
		"/clone/misc/dache" : 1,
	]));
	set("no_fight", "1");
	set("outdoors", "taishan");
	set("coor/x", 400);
	set("coor/y", 530);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
