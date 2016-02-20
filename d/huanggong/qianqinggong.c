// Room: /d/huanggong/qianqinggong.c

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "乾清宫");
	set("long", @LONG
这是皇上的寝宫. 乾清意为天下清宁平和. 皇上也常在这里选派官
吏, 批阅文章, 召见臣下. 宫上横匾“正大光明”, 是顺治帝的亲笔手
书, 以表明自己所作所为是正直大度和光明磊落的. 殿内四根柱子上悬
着两幅楹联, 一幅康熙大帝的御笔(kangxi), 另一幅是乾隆皇帝的御笔
(qianlong).
LONG
	);
	set("item_desc", ([
		"kangxi" : "
表正万邦 慎厥身修思永
弘敷五典 无轻民事惟难
\n",
		"qianlong" : "
克宽克仁 皇建其有极
惟精惟一 道积于厥躬
\n",
	]));
	set("exits", ([
		"west"      : __DIR__"huangqin",
		"east"      : __DIR__"duanning",
		"south"     : __DIR__"qianqingmen",
		"north"     : __DIR__"jiaotaidian",
		"southeast" : __DIR__"yushufang",
		"southwest" : __DIR__"jingshifang",
	]));
	set("objects", ([
		__DIR__"npc/zhangkangnian": 1,
		__DIR__"npc/zhaoqixian": 1,
	]));
	set("coor/x", -200);
	set("coor/y", 5290);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}