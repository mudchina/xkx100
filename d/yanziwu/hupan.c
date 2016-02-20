// Room: /d/yanziwu/hupan.c
// Date: Feb.14.1998 by Java

#include <ansi.h>
inherit RIVER;

void create()
{
	::create();
	set("short", "太湖湖畔");
	set("long", @LONG
太湖(hu)处江浙之间。她襟带三江，东南之水尽汇于此，周行五百
里，古称五湖。矗立湖岸，唯见长天远波，放眼皆碧，七十二峰苍翠挺
立在三万六千顷波涛之中，使人心襟大开，直欲仰天长啸，方能表此喜
乐。
LONG );
	set("exits", ([
		"northeast" : "/d/suzhou/road5",
	]));
	set("item_desc", ([
		"hu":HIC"\n近湖畔处有一叶小舟，舟上一个绿衫姑娘正在戏水。喊("HIY"yell"HIC")一声试试吧。\n倘若你自负轻功绝佳,也可直接"
                        "渡水(" HIY "cross" HIC ")踏江而过。\n" NOR,
	]));
	set("objects", ([
		"/clone/misc/dache" : 1,
	]));
	set("outdoors", "yanziwu");
	set("coor/x", 840);
	set("coor/y", -1140);
	set("coor/z", 0);
  set("yell_about", "姑娘");             // yell 船家
  set("river_type", "湖");               // 江面上传来回响
  set("need_dodge",300);                 // 需要多少轻功
  set("come_msg_out",   "一尾小舟缓缓地驶了过来，一个采莲少女招手让你登舟。\n");
  set("busy_msg",       "只听得湖面上隐隐传来：“就来了啦……”\n");
  set("wait_msg",       "湖畔一尾小舟上一个绿衫少女细声说到：侬有啥事体。\n");
  set("leave_msg_out",  "少女竹篙一点，小舟离岸向湖心滑去。\n");
  set("leave_msg_in",   "\n少女说了一声“坐稳喽”，声音极甜极清，令人一听之下，说不出的舒适。然后竹篙一点，扁舟向湖心滑去。\n");
  set("come_msg_in",    "少女说: “到啦，上岸吧。”，随即一点竹篙，把舟泊好。\n");
  set("item_desc/river", HIC "\n近湖畔处有一叶小舟，舟上一个绿衫姑娘正在戏水，也许喊("
                         HIY "yell" HIC ")一声姑娘\n(" HIY "boat" HIC
                        ")就能听见。倘若你自负轻功绝佳,也可直接"
                        "渡水(" HIY "cross" HIC ")踏江而过。\n" NOR);
  set("boat_short", "小舟");    
  set("boat_desc",  @LONG
碧绿湖面飘荡的一叶小舟，一个绿衫少女手执双桨，缓缓划水，口
中唱着吴侬小曲。歌声娇柔无那，欢悦动心。一双纤手皓肤如玉，映着
绿波，便如透明一般。
LONG );
  set("to",         __DIR__"muti");  // 船的终点 /*   必选   */
	setup();
}