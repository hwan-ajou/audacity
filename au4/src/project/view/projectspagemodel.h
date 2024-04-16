/*
 * SPDX-License-Identifier: GPL-3.0-only
 * Audacity-CLA-applies
 *
 * Audacity
 * Music Composition & Notation
 *
 * Copyright (C) 2024 Audacity BVBA and others
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 3 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */
#ifndef AU_PROJECT_PROJECTSPAGEMODEL_H
#define AU_PROJECT_PROJECTSPAGEMODEL_H

#include <QObject>

#include "modularity/ioc.h"
#include "iprojectconfiguration.h"
#include "actions/iactionsdispatcher.h"
#include "iinteractive.h"
#include "cloud/musescorecom/imusescorecomservice.h"

class QString;

namespace au::project {
class ProjectsPageModel : public QObject
{
    Q_OBJECT

    INJECT(IProjectConfiguration, configuration)
    INJECT(muse::actions::IActionsDispatcher, dispatcher)
    INJECT(muse::IInteractive, interactive)
    INJECT(muse::cloud::IMuseScoreComService, museScoreComService)

    Q_PROPERTY(int tabIndex READ tabIndex WRITE setTabIndex NOTIFY tabIndexChanged)
    Q_PROPERTY(ViewType viewType READ viewType WRITE setViewType NOTIFY viewTypeChanged)

public:
    explicit ProjectsPageModel(QObject* parent = nullptr);

    int tabIndex() const;
    void setTabIndex(int index);

    enum ViewType {
        Grid = int(IProjectConfiguration::HomeProjectsPageViewType::Grid),
        List = int(IProjectConfiguration::HomeProjectsPageViewType::List),
    };
    Q_ENUM(ViewType);

    ViewType viewType() const;
    void setViewType(ViewType type);

    Q_INVOKABLE void createNewProject();
    Q_INVOKABLE void openOther();
    Q_INVOKABLE void openScore(const QString& scorePath, const QString& displayNameOverride);
    Q_INVOKABLE void openScoreManager();

signals:
    void tabIndexChanged();
    void viewTypeChanged();
};
}

#endif // AU_PROJECT_PROJECTSPAGEMODEL_H
