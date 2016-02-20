// Room: /yixing/taihu.c
// Date: Nov.18 1998 by Winder

#include <ansi.h>
inherit RIVER;

void create()
{
	::create();
	set("short", "太湖");
	set("long", @LONG
太湖古称五湖，襟带三州，周行五百里，东南之水皆归于此。其时
但见长天无波，放眼皆碧，七十二峰苍翠挺立于三万六千顷波涛之中，
不觉令人心怀大畅。由此登船可前往太湖之中的归云庄。
LONG );
	set("outdoors", "yixing");
	set("exits", ([
		"north" : __DIR__"shanlu1",
	]));
	set("objects", ([
		"/d/guiyun/npc/xiaolu" : 1,
	]));
	set("item_desc", ([
		"hu"  : HIC "\n近湖畔处有一叶小舟，舟上一个老梢公正在划桨，也许大声喊("
            HIY "yell" HIC ")一声船\n家(" HIY "boat" HIC
            ")就能听见。倘若你自负轻功绝佳,也可直接"
            "渡水(" HIY "cross" HIC ")踏水而过。\n" NOR,
	]));
	set("coor/x", 230);
	set("coor/y", -190);
	set("coor/z", 0);
  set("yell_about", "船家");             // yell 船家
  set("river_type", "湖");               // 江面上传来回响
  set("need_dodge",300);                 // 需要多少轻功
  set("come_msg_out",   "一叶扁舟缓缓地驶了过来，艄公将一块踏脚板搭上堤岸，以便乘客上下。\n");
  set("busy_msg",       "只听得湖面上隐隐传来：“别急嘛，这儿正忙着呐……”\n");
  set("wait_msg",       "岸边一只渡船上的老艄公说道：正等着你呢，上来吧。\n");
  set("leave_msg_out",  "艄公把踏脚板收了起来，竹篙一点，扁舟向湖心驶去。\n");
  set("leave_msg_in",   "艄公把踏脚板收起来，说了一声“坐稳喽”，竹篙一点，扁舟向湖心驶去。\n");
  set("come_msg_in",    "艄公说“到啦，上岸吧”，随即把一块踏脚板搭上堤岸。\n");
  set("item_desc/river", HIC "\n近湖畔处有一叶小舟，舟上一个老梢公正在划桨，也许大声喊("
                         HIY "yell" HIC ")一声船\n家(" HIY "boat" HIC
                         ")就能听见。倘若你自负轻功绝佳,也可直接"
                        "渡水(" HIY "cross" HIC ")踏水而过。\n" NOR );
  set("boat_short", "渡船");    
  set("boat_desc",  @LONG
离岸渐远，四望空阔，真是莫知天地之在湖海，抑或是湖海之在天
地。老梢公在船尾悠闲地划着水。
LONG );                                   // 渡船上的描述
  set("to",         "/d/guiyun/matou");  // 船的终点 /*   必选   */
	setup();
}