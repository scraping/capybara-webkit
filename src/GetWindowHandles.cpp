#include "GetWindowHandles.h"
#include "WebPageManager.h"
#include <QStringList>

GetWindowHandles::GetWindowHandles(WebPage *page, QStringList &arguments, QObject *parent) : Command(page, arguments, parent) {
}

void GetWindowHandles::start() {
  QListIterator<WebPage *> pageIterator =
    WebPageManager::getInstance()->iterator();

  QString handles = "[";
  QStringList stringList;

  while (pageIterator.hasNext()) {
    stringList.append("\"" + pageIterator.next()->uuid() + "\"");
  }

  handles += stringList.join(",") + "]";

  emit finished(new Response(true, handles));
}
