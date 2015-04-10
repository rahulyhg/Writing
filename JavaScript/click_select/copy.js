                function getCnblogsCodeContainer(n) {
                    var t = $(n).next("code");
                    return t.length == 0 && (t = $(n).closest("pre")), t
                };

                function getCnblogsCodeText(n) {
                    var t="\n"+$(n).html().replace(/&nbsp;/g," ").replace(/<br\s*\/?>/ig,"\n").replace(/<[^>]*>/g,"");
                    return t=t.replace(/\n(\s*\d+\s)/ig,"\n"),t=t.replace(/\r\n/g,"\n"),t=t.replace(/\nView Code/g,""),typeof Encoder!=undefined&&(t=Encoder.htmlDecode(t)),$.trim(t)
                };

                function copyCnblogsCode(n) {
                    var i = getCnblogsCodeContainer(n),
                        u = getCnblogsCodeText(i),
                        t = document.createElement("textarea"),
                        r;
                    $(t).val(u);
                    $(t).css("width", $(i).width());
                    r = $(i).height() * .8;
                    r > 600 && (r = 600);
                    $(t).css("height", r);
                    $(t).css("font-family", "Courier New");
                    $(t).css("font-size", "12px");
                    $(t).css("line-height", "1.5");
                    $(i).html(t);
                    $(t).select();
                    $("<div>按 Ctrl+C 复制代码<\/div>").insertBefore($(t));
                    $("<div>按 Ctrl+C 复制代码<\/div>").insertAfter($(t));
                };
